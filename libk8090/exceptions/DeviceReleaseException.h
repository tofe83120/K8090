/*
 * DeviceReleaseException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef DEVICERELEASEEXCEPTION_H_
#define DEVICERELEASEEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class DeviceReleaseException: public gsg::velleman::k8090::K8090Exception {
public:
	DeviceReleaseException();
	DeviceReleaseException(string message);
	~DeviceReleaseException() throw ();
};

}
}
}

#endif /* DEVICERELEASEEXCEPTION_H_ */
