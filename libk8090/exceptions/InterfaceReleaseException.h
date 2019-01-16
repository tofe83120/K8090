/*
 * InterfaceReleaseException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef INTERFACERELEASEEXCEPTION_H_
#define INTERFACERELEASEEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class InterfaceReleaseException: public gsg::velleman::k8090::K8090Exception {
public:
	InterfaceReleaseException();
	InterfaceReleaseException(string message);
	~InterfaceReleaseException() throw ();
};

}
}
}

#endif /* INTERFACERELEASEEXCEPTION_H_ */
