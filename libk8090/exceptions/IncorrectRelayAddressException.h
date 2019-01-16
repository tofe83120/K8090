/*
 * IncorrectRelayAddressException.h
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#ifndef INCORRECTRELAYADDRESSEXCEPTION_H_
#define INCORRECTRELAYADDRESSEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class IncorrectRelayAddressException: public gsg::velleman::k8090::K8090Exception {
public:
	IncorrectRelayAddressException();
	IncorrectRelayAddressException(string message);
	~IncorrectRelayAddressException() throw ();
};

}
}
}

#endif /* INCORRECTRELAYADDRESSEXCEPTION_H_ */
