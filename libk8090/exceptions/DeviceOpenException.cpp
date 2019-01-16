/*
 * DeviceOpenException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "DeviceOpenException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

DeviceOpenException::DeviceOpenException() :
	K8090Exception() {
}
DeviceOpenException::DeviceOpenException(string message) :
	K8090Exception(message) {
}
DeviceOpenException::~DeviceOpenException() throw () {
}

}
}
}
