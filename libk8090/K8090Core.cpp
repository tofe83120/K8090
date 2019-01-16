/*
 * K8090Core.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include <iostream>
#include <string>
#include <sstream>

#include <usb.h>

#include "K8090Core.h"

using namespace std;

// ******************************************

//#define DEBUG 1

// ******************************************

// ******************************************

#define VELLEMAN_VENDOR_ID 0x10cf
#define K8090_PRODUCT_ID 0x8090

#define USB_TIMEOUT 20

// ******************************************

#define PACKET_LEN 7

// ******************************************

#define EMPTY_VALUE 0x00

#define PACKET_BEGIN_VALUE 0x04
#define PACKET_END_VALUE 0x0F

// ******************************************

namespace gsg {
namespace velleman {
namespace k8090 {

// **************************
// ***** public methods *****
// **************************

K8090Core::K8090Core() {
#ifdef DEBUG
	cout << "> K8090Core" << endl;
#endif

	// ***** init *****
	usb_busses = NULL;
	usb_device = NULL;

	// ***** init USB *****
	initUsb();
}

K8090Core::~K8090Core() throw (InterfaceReleaseException, DeviceResetException,
		DeviceCloseException) {
#ifdef DEBUG
	cout << "> ~K8090Core" << endl;
#endif

	// ***** close device *****
	close();

	// ***** release USB *****
	releaseUsb();
}

// ***** device control methods *****

void K8090Core::open() throw (DeviceDetachException, InterfaceClaimException,
		MissingBoardException) {
#ifdef DEBUG
	cout << "> open" << endl;
#endif

	// ***** loop through USB devices *****
	struct usb_bus * bus;
	for (bus = usb_busses; bus; bus = bus->next) {

		struct usb_device * device;
		for (device = bus->devices; device; device = device->next) {

			// ***** check if Velleman K8090 *****
			if ((device->descriptor.idVendor == VELLEMAN_VENDOR_ID)
					&& (device->descriptor.idProduct == K8090_PRODUCT_ID)) {
#ifdef DEBUG
				cout << "> open - found = " << device->descriptor.idVendor << "/" << device->descriptor.idProduct << endl;
#endif

				// ***** open device *****
				usb_device = usb_open(device);

				// ***** detach device from OS *****
				char driver_name[256] = "";
				if (usb_get_driver_np(usb_device, interface_address,
						driver_name, 256) == 0)
					if (usb_detach_kernel_driver_np(usb_device,
							interface_address) < 0)
						throw DeviceDetachException(
								"Cannot detach device from OS driver");

				// ***** claim device interface *****
				if (usb_claim_interface(usb_device, interface_address) < 0)
					throw InterfaceClaimException(
							"Cannot claim device interface");

				return;
			}
		}
	}

	// ***** board not found *****
	throw MissingBoardException(
			"Cannot find K8090 board, check if correctly connected");
}

void K8090Core::close() throw (InterfaceReleaseException, DeviceResetException,
		DeviceCloseException) {
#ifdef DEBUG
	cout << "> close" << endl;
#endif

	// ***** check device *****
	if (usb_device == NULL)
		return;

	// ***** relase interface *****

	if (usb_release_interface(usb_device, interface_address) < 0)
		throw InterfaceReleaseException("Cannot release device interface");

	if (usb_reset(usb_device) < 0)
		throw DeviceResetException("Cannot reset device");

	if (usb_close(usb_device) < 0)
		throw DeviceCloseException("Cannot close device");

	// ***** cleanup *****
	usb_device = NULL;
}

// *****************************
// ***** protected methods *****
// *****************************

// ***** accessors *****

void K8090Core::setInterfaceAddress(int i_addr) {
#ifdef DEBUG
	cout << "> setInterfaceAddress" << endl;
#endif

	interface_address = i_addr;
}

int K8090Core::getInterfaceAddress() {
#ifdef DEBUG
	cout << "> getInterfaceAddress" << endl;
#endif

	return interface_address;
}

void K8090Core::setInputEndpointAddress(int in_ep_addr) {
#ifdef DEBUG
	cout << "> setInputEndpointAddress" << endl;
#endif

	input_endpoint_address = in_ep_addr;
}

int K8090Core::getInputEndpointAddress() {
#ifdef DEBUG
	cout << "> getInputEndpointAddress" << endl;
#endif

	return input_endpoint_address;
}

void K8090Core::setOutputEndpointAddress(int out_ep_addr) {
#ifdef DEBUG
	cout << "> setOutputEndpointAddress" << endl;
#endif

	output_endpoint_address = out_ep_addr;
}

int K8090Core::getOutputEndpointAddress() {
#ifdef DEBUG
	cout << "> getOutputEndpointAddress : " << endl;
#endif

	return output_endpoint_address;
}

// ***** read / write methods *****

K8090_data K8090Core::readData() throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException, DataReadException) {
#ifdef DEBUG
	cout << "> readData" << endl;
#endif

	// ***** check device *****
	if (usb_device == NULL)
		open();

	// ***** clear data area *****
	char buffer[PACKET_LEN];

	// ***** read data from device *****
	for (int i = 0; i < 3; i++) {
		int read_status = usb_bulk_read(usb_device, input_endpoint_address,
				buffer, PACKET_LEN, USB_TIMEOUT);

		K8090_data data = mapBuffer2K8090Data(buffer);
		if ((read_status == PACKET_LEN) && (data.stx == PACKET_BEGIN_VALUE)
				&& (data.etx == PACKET_END_VALUE) && (data.chk
				== calculateChecksum(data.cmd, data.msk, data.p1, data.p2))) {
#ifdef DEBUG
			cout << "> readData - buffer = " << displayHexadecimal(buffer, PACKET_LEN) << endl;
#endif
			return data;
		}
	}

	// ***** read error *****
	throw DataReadException("Cannot read device");
}

void K8090Core::writeData(char cmd, char mask, char param1, char param2)
		throw (DeviceDetachException, InterfaceClaimException,
		MissingBoardException, DataWriteException) {
#ifdef DEBUG
	cout << "> writeData" << endl;
#endif

	// ***** check device *****
	if (usb_device == NULL)
		open();

	// ***** empty device read queue *****
	flushReadQueue();

	// ***** copy data into data area *****
	char p1 = EMPTY_VALUE;
	if (param1 != EMPTY_VALUE)
		p1 = param1;

	char p2 = EMPTY_VALUE;
	if (param2 != EMPTY_VALUE)
		p2 = param2;

	char checksum = calculateChecksum(cmd, mask, p1, p2);

	char buffer[PACKET_LEN];
	buffer[0] = PACKET_BEGIN_VALUE;
	buffer[1] = cmd;
	buffer[2] = mask;
	buffer[3] = p1;
	buffer[4] = p2;
	buffer[5] = checksum;
	buffer[6] = PACKET_END_VALUE;

#ifdef DEBUG
	cout << "> writeData - buffer = " << displayHexadecimal(buffer, PACKET_LEN) << endl;
#endif

	// ***** write data to device *****
	for (int i = 0; i < 3; i++) {
		int write_status = usb_bulk_write(usb_device, output_endpoint_address,
				buffer, PACKET_LEN, USB_TIMEOUT);

		if (write_status == PACKET_LEN)
			return;
	}

	// ***** write error *****
	throw DataWriteException("Cannot write device");
}

// ***** utilities *****

string K8090Core::displayBinary(char data) {
	string result = "00000000";
	unsigned short mask = 0x80;

	int i = 0;
	while (mask) {
		if (data & mask)
			result[i] = '1';

		i++;
		mask >>= 1;
	}

	return result;
}

string K8090Core::displayHexadecimal(char * buffer, int length) {
	ostringstream result;

	for (int i = 0; i < length; i++) {
		result << hex << uppercase << (int) buffer[i];
		result << " ";
	}
	return result.str(); //.trim();
}

string K8090Core::displayHexadecimal(K8090_data data) {
	ostringstream result;

	result << hex << uppercase << data.stx << " ";
	result << hex << uppercase << data.cmd << " ";
	result << hex << uppercase << data.msk << " ";
	result << hex << uppercase << data.p1 << " ";
	result << hex << uppercase << data.p2 << " ";
	result << hex << uppercase << data.chk << " ";
	result << hex << uppercase << data.etx;

	return result.str(); //.trim();
}

// ***************************
// ***** private methods *****
// ***************************

// ***** USB control methods *****

void K8090Core::initUsb() {
#ifdef DEBUG
	cout << "> initUsb" << endl;
#endif

	if (usb_busses == NULL) {
		usb_init();
		usb_find_busses();
		usb_find_devices();
		usb_busses = usb_get_busses();

		//usb_set_debug(3);
	}
}

void K8090Core::releaseUsb() {
#ifdef DEBUG
	cout << "> releaseUsb" << endl;
#endif

	if (usb_busses != NULL) {
		// TODO : find USB release code
	}
}

// ***** USB read/write methods *****

K8090_data K8090Core::mapBuffer2K8090Data(char * buffer) {
	K8090_data result;

	result.stx = buffer[0];
	result.cmd = buffer[1];
	result.msk = buffer[2];
	result.p1 = buffer[3];
	result.p2 = buffer[4];
	result.chk = buffer[5];
	result.etx = buffer[6];

	return result;
}

void K8090Core::flushReadQueue() {
#ifdef DEBUG
	cout << "> flushReadQueue" << endl;
#endif

	// ***** check device *****
	if (usb_device == NULL)
		open();

	// ***** clear data area *****
	char buffer[PACKET_LEN];

	// ***** read data from device *****
	int read_status;
	while ((read_status = usb_bulk_read(usb_device, input_endpoint_address,
			buffer, PACKET_LEN, USB_TIMEOUT)) == PACKET_LEN) {
#ifdef DEBUG
		cout << "> flushReadQueue = flushing ... " << endl;
#endif
	}
}

char K8090Core::calculateChecksum(char cmd, char mask, char p1, char p2) {
	return ~(PACKET_BEGIN_VALUE + cmd + mask + p1 + p2) + 1;
}

}
}
}
