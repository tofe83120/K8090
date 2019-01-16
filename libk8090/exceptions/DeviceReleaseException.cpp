/*
 * DeviceReleaseException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "DeviceReleaseException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

DeviceReleaseException::DeviceReleaseException() :
	K8090Exception() {
}
DeviceReleaseException::DeviceReleaseException(string message) :
	K8090Exception(message) {
}
DeviceReleaseException::~DeviceReleaseException() throw () {
}

}
}
}
