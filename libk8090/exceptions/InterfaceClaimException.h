/*
 * InterfaceClaimException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef INTERFACECLAIMEXCEPTION_H_
#define INTERFACECLAIMEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class InterfaceClaimException: public gsg::velleman::k8090::K8090Exception {
public:
	InterfaceClaimException();
	InterfaceClaimException(string message);
	~InterfaceClaimException() throw ();
};

}
}
}

#endif /* INTERFACECLAIMEXCEPTION_H_ */
