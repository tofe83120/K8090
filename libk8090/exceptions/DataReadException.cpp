/*
 * DataReadException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "DataReadException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

DataReadException::DataReadException() :
	K8090Exception() {
}
DataReadException::DataReadException(string message) :
	K8090Exception(message) {
}
DataReadException::~DataReadException() throw () {
}

}
}
}
