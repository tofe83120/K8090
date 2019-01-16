/*
 * K8090Listener.cpp
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */
#include <iostream>

#include "K8090Listener.h"

using namespace std;

// ******************************************

#define USB_EVENT_INTERFACE_NB 0
#define USB_EVENT_IN_EP 0x82		/* USB event input endpoint */

// ******************************************

namespace gsg {
namespace velleman {
namespace k8090 {

// **************************
// ***** public methods *****
// **************************

K8090Listener::K8090Listener() {
#ifdef DEBUG
	cout << "> K8090Listener" << endl;
#endif

	setInterfaceAddress(USB_EVENT_INTERFACE_NB);
	setInputEndpointAddress(USB_EVENT_IN_EP);

	listen = false;
}

K8090Listener::~K8090Listener() throw (InterfaceReleaseException,
		DeviceResetException, DeviceCloseException) {
#ifdef DEBUG
	cout << "> ~K8090Listener" << endl;
#endif
}

// ***** device commands methods *****

void K8090Listener::startListening() throw (DeviceDetachException,
		InterfaceClaimException, MissingBoardException, DataReadException) {
	listen = true;
	while (listen) {
		// ***** read next message *****
		K8090_data data;
		try {
			data = readData();
			cout << displayHexadecimal(data) << endl;
		} catch (DataReadException) {
		}

		// ***** wait *****
	}
}

void K8090Listener::stopListening() {
	listen = false;
}

}
}
}
