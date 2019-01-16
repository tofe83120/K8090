/*
 * DeviceResetException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "DeviceResetException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

DeviceResetException::DeviceResetException() :
	K8090Exception() {
}
DeviceResetException::DeviceResetException(string message) :
	K8090Exception(message) {
}
DeviceResetException::~DeviceResetException() throw () {
}

}
}
}
