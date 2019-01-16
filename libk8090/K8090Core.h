/*
 * K8090Core.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef K8090CORE_H_
#define K8090CORE_H_

#include <string>

#include "exceptions/DeviceDetachException.h"
#include "exceptions/DeviceOpenException.h"
#include "exceptions/DeviceCloseException.h"
#include "exceptions/DeviceResetException.h"
#include "exceptions/InterfaceClaimException.h"
#include "exceptions/InterfaceReleaseException.h"

#include "exceptions/DataReadException.h"
#include "exceptions/DataWriteException.h"

#include "exceptions/MissingBoardException.h"
#include "exceptions/IncorrectRelayAddressException.h"
#include "exceptions/IncorrectTimerDelayException.h"

#include "K8090Core.h"

using namespace std;

namespace gsg {
namespace velleman {
namespace k8090 {

// ******************************

struct K8090_data {

	char stx;
	char cmd;
	char msk;
	char p1;
	char p2;
	char chk;
	char etx;

};

// ******************************

class K8090Core {

public:

	K8090Core();
	virtual ~K8090Core() throw (InterfaceReleaseException,
			DeviceResetException, DeviceCloseException);

	// ***** device control methods *****
	void open() throw (DeviceDetachException, InterfaceClaimException,
			MissingBoardException);
	void close() throw (InterfaceReleaseException, DeviceResetException,
			DeviceCloseException);

protected:

	// ***** accessors *****
	void setInterfaceAddress(int interface_address);
	int getInterfaceAddress();

	void setInputEndpointAddress(int in_ep_addr);
	int getInputEndpointAddress();

	void setOutputEndpointAddress(int out_ep_addr);
	int getOutputEndpointAddress();

	// ***** device read/write methods *****
	K8090_data readData() throw (DeviceDetachException,
			InterfaceClaimException, MissingBoardException, DataReadException);
	void writeData(char cmd, char mask, char param1, char param2)
			throw (DeviceDetachException, InterfaceClaimException,
			MissingBoardException, DataWriteException);

	// ***** utilities *****
	string displayBinary(char data);
	string displayHexadecimal(char * buffer, int length);
	string displayHexadecimal(K8090_data data);

private:

	// ***** properties *****
	struct usb_bus * usb_busses;
	struct usb_dev_handle * usb_device;

	int interface_address;
	int input_endpoint_address;
	int output_endpoint_address;

	// ***** USB control methods *****
	void initUsb();
	void releaseUsb();

	// ***** device read/write methods *****
	void flushReadQueue();
	K8090_data mapBuffer2K8090Data(char * buffer);
	char calculateChecksum(char cmd, char mask, char p1, char p2);
};

}
}
}

#endif /* K8090CORE_H_ */
