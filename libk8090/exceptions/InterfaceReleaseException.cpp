/*
 * InterfaceReleaseException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "InterfaceReleaseException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

InterfaceReleaseException::InterfaceReleaseException() :
	K8090Exception() {
}
InterfaceReleaseException::InterfaceReleaseException(string message) :
	K8090Exception(message) {
}
InterfaceReleaseException::~InterfaceReleaseException() throw () {
}

}
}
}
