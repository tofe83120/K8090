/*
 * DeviceCloseException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "DeviceCloseException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

DeviceCloseException::DeviceCloseException() :
	K8090Exception() {
}
DeviceCloseException::DeviceCloseException(string message) :
	K8090Exception(message) {
}
DeviceCloseException::~DeviceCloseException() throw () {
}

}
}
}
