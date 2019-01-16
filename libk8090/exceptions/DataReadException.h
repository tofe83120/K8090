/*
 * DataReadException.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef DATAREADEXCEPTION_H_
#define DATAREADEXCEPTION_H_

#include "K8090Exception.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class DataReadException: public gsg::velleman::k8090::K8090Exception {
public:
	DataReadException();
	DataReadException(string message);
	~DataReadException() throw ();
};

}
}
}

#endif /* DATAREADEXCEPTION_H_ */
