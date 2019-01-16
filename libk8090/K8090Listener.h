/*
 * K8090Listener.h
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#ifndef K8090LISTENER_H_
#define K8090LISTENER_H_

#include "K8090Core.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class K8090Listener: public gsg::velleman::k8090::K8090Core {

public:
	K8090Listener();
	virtual ~K8090Listener() throw (InterfaceReleaseException,
			DeviceResetException, DeviceCloseException);

	// ***** device commands methods *****
	void startListening() throw (DeviceDetachException,
			InterfaceClaimException, MissingBoardException, DataReadException);
	void stopListening();

private:
	bool listen;

};

}
}
}

#endif /* K8090LISTENER_H_ */
