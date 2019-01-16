/*
 * UnknownCommandException.cpp
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#include "UnknownCommandException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

UnknownCommandException::UnknownCommandException() :
	K8090Exception() {
}
;

UnknownCommandException::UnknownCommandException(string message) :
	K8090Exception(message) {
}
;

UnknownCommandException::~UnknownCommandException() throw () {
}
;

}
}
}
