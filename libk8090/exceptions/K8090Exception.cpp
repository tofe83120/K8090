/*
 * K8090Exception.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

K8090Exception::K8090Exception() :
	exception() {
	set_message("K8090 exception occurred");
}

K8090Exception::K8090Exception(string message) :
	exception() {
	set_message(message);
}

K8090Exception::~K8090Exception() throw () {
}

void K8090Exception::set_message(string message) {
	msg = message;
}

const string K8090Exception::what() throw () {
	return msg;
}

}
}
}
