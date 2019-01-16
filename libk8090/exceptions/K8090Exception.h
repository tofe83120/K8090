/*
 * K8090Exception.h
 *
 *  Created on: 17 août 2011
 *      Author: cgarcia
 */

#ifndef K8090EXCEPTION_H_
#define K8090EXCEPTION_H_

#include <string>
#include <exception>

using namespace std;

namespace gsg {
namespace velleman {
namespace k8090 {

class K8090Exception: public exception {

public:
	K8090Exception();
	K8090Exception(string message);
	virtual ~K8090Exception() throw ();

	void set_message(string message);
	virtual const string what() throw ();

private:
	string msg;

};

}
}
}

#endif /* K8090EXCEPTION_H_ */
