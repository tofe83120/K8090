/*
 * MissingBoardException.h
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#ifndef MISSINGBOARDEXCEPTION_H_
#define MISSINGBOARDEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class MissingBoardException: public gsg::velleman::k8090::K8090Exception {
public:
	MissingBoardException();
	MissingBoardException(string message);
	~MissingBoardException() throw ();
};

}
}
}

#endif /* MISSINGBOARDEXCEPTION_H_ */
