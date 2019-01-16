/*
 * IncorrectTimerDelayException.h
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#ifndef INCORRECTTIMERDELAYEXCEPTION_H_
#define INCORRECTTIMERDELAYEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class IncorrectTimerDelayException: public gsg::velleman::k8090::K8090Exception {
public:
	IncorrectTimerDelayException();
	IncorrectTimerDelayException(string message);
	~IncorrectTimerDelayException() throw ();
};

}
}
}

#endif /* INCORRECTTIMERDELAYEXCEPTION_H_ */
