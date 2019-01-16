/*
 * InterfaceClaimException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "InterfaceClaimException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

InterfaceClaimException::InterfaceClaimException() :
	K8090Exception() {
}
InterfaceClaimException::InterfaceClaimException(string message) :
	K8090Exception(message) {
}
InterfaceClaimException::~InterfaceClaimException() throw () {
}

}
}
}
