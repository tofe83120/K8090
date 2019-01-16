/*
 * IncorrectTimerDelayException.cpp
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#include "IncorrectTimerDelayException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

IncorrectTimerDelayException::IncorrectTimerDelayException() :
	K8090Exception() {
}
IncorrectTimerDelayException::IncorrectTimerDelayException(string message) :
	K8090Exception(message) {
}
IncorrectTimerDelayException::~IncorrectTimerDelayException() throw () {
}

}
}
}
