/*
 * UnknownCommandException.h
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#ifndef UNKNOWNCOMMANDEXCEPTION_H_
#define UNKNOWNCOMMANDEXCEPTION_H_

#include "exceptions/K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class UnknownCommandException: public gsg::velleman::k8090::K8090Exception {
public:
	UnknownCommandException();
	UnknownCommandException(string message);
	virtual ~UnknownCommandException() throw ();
};

}
}
}

#endif /* UNKNOWNCOMMANDEXCEPTION_H_ */
