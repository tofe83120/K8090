/*
 * DataWriteException.cpp
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#include "DataWriteException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

DataWriteException::DataWriteException() :
	K8090Exception() {
}
DataWriteException::DataWriteException(string message) :
	K8090Exception(message) {
}
DataWriteException::~DataWriteException() throw () {
}

}
}
}
