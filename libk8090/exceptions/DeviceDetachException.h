/*
 * DeviceDetachException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef DEVICEDETACHEXCEPTION_H_
#define DEVICEDETACHEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class DeviceDetachException: public gsg::velleman::k8090::K8090Exception {
public:
	DeviceDetachException();
	DeviceDetachException(string message);
	~DeviceDetachException() throw ();
};

}
}
}

#endif /* DEVICEDETACHEXCEPTION_H_ */
