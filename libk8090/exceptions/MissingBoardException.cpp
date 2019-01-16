/*
 * MissingBoardException.cpp
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#include "MissingBoardException.h"

namespace gsg {
namespace velleman {
namespace k8090 {

MissingBoardException::MissingBoardException() :
	K8090Exception() {
}
MissingBoardException::MissingBoardException(string message) :
	K8090Exception(message) {
}
MissingBoardException::~MissingBoardException() throw () {
}

}
}
}
