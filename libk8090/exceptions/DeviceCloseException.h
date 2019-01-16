/*
 * DeviceCloseException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef DEVICECLOSEEXCEPTION_H_
#define DEVICECLOSEEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class DeviceCloseException: public gsg::velleman::k8090::K8090Exception {
public:
	DeviceCloseException();
	DeviceCloseException(string message);
	~DeviceCloseException() throw ();
};

}
}
}

#endif /* DEVICECLOSEEXCEPTION_H_ */
