/*
 * DeviceDetachException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "DeviceDetachException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

DeviceDetachException::DeviceDetachException() :
	K8090Exception() {
}
DeviceDetachException::DeviceDetachException(string message) :
	K8090Exception(message) {
}
DeviceDetachException::~DeviceDetachException() throw () {
}

}
}
}
