/*
 * DeviceResetException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef DEVICERESETEXCEPTION_H_
#define DEVICERESETEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class DeviceResetException: public gsg::velleman::k8090::K8090Exception {
public:
	DeviceResetException();
	DeviceResetException(string message);
	~DeviceResetException() throw ();
};

}
}
}

#endif /* DEVICERESETEXCEPTION_H_ */
