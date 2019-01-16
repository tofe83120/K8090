/*
 * IncorrectRelayAddressException.cpp
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#include "IncorrectRelayAddressException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

IncorrectRelayAddressException::IncorrectRelayAddressException() :
	K8090Exception() {
}
IncorrectRelayAddressException::IncorrectRelayAddressException(string message) :
	K8090Exception(message) {
}
IncorrectRelayAddressException::~IncorrectRelayAddressException() throw () {
}

}
}
}
