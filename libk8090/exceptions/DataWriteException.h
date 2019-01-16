/*
 * DataWriteException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef DATAWRITEEXCEPTION_H_
#define DATAWRITEEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class DataWriteException: public gsg::velleman::k8090::K8090Exception {
public:
	DataWriteException();
	DataWriteException(string message);
	~DataWriteException() throw ();
};

}
}
}

#endif /* DATAWRITEEXCEPTION_H_ */
