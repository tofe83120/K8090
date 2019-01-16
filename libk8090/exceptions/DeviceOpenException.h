/*
 * DeviceOpenException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef DEVICEOPENEXCEPTION_H_
#define DEVICEOPENEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class DeviceOpenException: public gsg::velleman::k8090::K8090Exception {
public:
	DeviceOpenException();
	DeviceOpenException(string message);
	~DeviceOpenException() throw ();
};

}
}
}

#endif /* DEVICEOPENEXCEPTION_H_ */
