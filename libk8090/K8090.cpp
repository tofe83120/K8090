/*
 * K8090.cpp
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#include <iostream>
#include <math.h>

#include "K8090.h"

using namespace std;

// ******************************************

#define USB_BULK_INTERFACE_NB 1
#define USB_BULK_OUT_EP 0x03		/* USB bulk output endpoint */
#define USB_BULK_IN_EP 0x83			/* USB bulk input endpoint */

// ******************************************

#define EMPTY_VALUE 0x00

#define CMD_SET_RELAY_ON 0x11
#define CMD_SET_RELAY_OFF 0x12
//#define CMD_SET_RELAY_TOGGLE 0x14
#define CMD_QRY_RELAY_STATUS 0x18

//#define CMD_SET_BUTTON_MODE 0x21
//#define CMD_QRY_BUTTON_MODE 0x22

#define CMD_SET_TIMER_START 0x41
//#define CMD_SET_TIMER_DEFAULT_DELAY 0x42
//#define CMD_QRY_TIMER_DEFAULT_DELAY 0x44

//#define CMD_EVT_BUTTON_STATUS 0x50
//#define CMD_EVT_RELAY_STATUS 0x51

//#define CMD_SYS_FACTORY_DEFAULTS 0x66
//#define CMD_SYS_JUMPER_STATUS 0x70
//#define CMD_SYS_FIRMWARE_VERSION 0x71

// ******************************************

namespace gsg {
namespace velleman {
namespace k8090 {

// **************************
// ***** public methods *****
// **************************

K8090::K8090() {
#ifdef DEBUG
	cout << "> K8090" << endl;
#endif

	setInterfaceAddress(USB_BULK_INTERFACE_NB);
	setOutputEndpointAddress(USB_BULK_OUT_EP);
	setInputEndpointAddress(USB_BULK_IN_EP);
}

K8090::~K8090() throw (InterfaceReleaseException, DeviceResetException,
		DeviceCloseException) {
#ifdef DEBUG
	cout << "> ~K8090" << endl;
#endif
}

// ***** device commands methods *****

char K8090::getAllRelayStatus() throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException, DataWriteException) {
#ifdef DEBUG
	cout << "> getRelayStatus" << endl;
#endif

	char cmd = CMD_QRY_RELAY_STATUS;

	writeData(cmd, EMPTY_VALUE, EMPTY_VALUE, EMPTY_VALUE);
	K8090_data response = readData();

	return response.p1;
}

bool K8090::getRelayStatus(int relay_address) throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException,
		IncorrectRelayAddressException, DataWriteException) {
#ifdef DEBUG
	cout << "> getRelayStatus" << endl;
#endif

	if (relay_address < 0 || relay_address > 7)
		throw IncorrectRelayAddressException("Incorrect relay number");

	char status = getAllRelayStatus();
	char mask = pow(2, relay_address);

	return (status & mask ? true : false);
}

void K8090::setRelayOn(int relay_address) throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException,
		IncorrectRelayAddressException, DataWriteException) {
#ifdef DEBUG
	cout << "> setRelayOn" << endl;
#endif

	if (relay_address < 0 || relay_address > 7)
		throw IncorrectRelayAddressException("Incorrect relay number : ");

	char cmd = CMD_SET_RELAY_ON;
	char mask = pow(2, relay_address);

	writeData(cmd, mask, EMPTY_VALUE, EMPTY_VALUE);
}

void K8090::setAllRelayOn() throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException, DataWriteException) {
#ifdef DEBUG
	cout << "> setAllRelayOn" << endl;
#endif

	char cmd = CMD_SET_RELAY_ON;
	char mask = 0xFF;

	writeData(cmd, mask, EMPTY_VALUE, EMPTY_VALUE);
}

void K8090::setRelayOff(int relay_address) throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException,
		IncorrectRelayAddressException, DataWriteException) {
#ifdef DEBUG
	cout << "> setRelayOff" << endl;
#endif

	if (relay_address < 0 || relay_address > 7)
		throw IncorrectRelayAddressException("Incorrect relay number");

	char cmd = CMD_SET_RELAY_OFF;
	char mask = pow(2, relay_address);

	writeData(cmd, mask, EMPTY_VALUE, EMPTY_VALUE);
}

void K8090::setAllRelayOff() throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException, DataWriteException) {
#ifdef DEBUG
	cout << "> setAllRelayOff" << endl;
#endif

	char cmd = CMD_SET_RELAY_OFF;
	char mask = 0xFF;

	writeData(cmd, mask, EMPTY_VALUE, EMPTY_VALUE);
}

void K8090::setTimerStart(int relay_address, short timer_delay)
		throw (DeviceDetachException, InterfaceClaimException,
		MissingBoardException, IncorrectRelayAddressException,
		IncorrectTimerDelayException, DataWriteException) {
#ifdef DEBUG
	cout << "> setTimerStart" << endl;
#endif

	if (relay_address < 0 || relay_address > 7)
		throw IncorrectRelayAddressException("Incorrect relay number");

	if (timer_delay < 0 || timer_delay > 65535)
		throw IncorrectTimerDelayException("Incorrect timer delay");

	char cmd = CMD_SET_TIMER_START;
	char mask = pow(2, relay_address);

	char p1 = (timer_delay >> 8);
	char p2 = ((timer_delay << 8) >> 8);

	writeData(cmd, mask, p1, p2);
}

}
}
}
