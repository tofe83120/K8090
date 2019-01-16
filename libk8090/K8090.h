/*
 * K8090.h
 *
 *  Created on: 18 août 2011
 *      Author: cgarcia
 */

#ifndef K8090_H_
#define K8090_H_

#include "K8090Core.h"

namespace gsg {
namespace velleman {
namespace k8090 {

class K8090: public gsg::velleman::k8090::K8090Core {
public:
	K8090();
	virtual ~K8090() throw (InterfaceReleaseException, DeviceResetException,
			DeviceCloseException);

	// ***** device commands methods *****

	char getAllRelayStatus() throw (DeviceDetachException,
			InterfaceClaimException, MissingBoardException, DataWriteException);

	bool getRelayStatus(int relay_address) throw (DeviceDetachException,
			InterfaceClaimException, MissingBoardException,
			IncorrectRelayAddressException, DataWriteException);

	void setRelayOn(int relay_address) throw (DeviceDetachException,
			InterfaceClaimException, MissingBoardException,
			IncorrectRelayAddressException, DataWriteException);

	void setAllRelayOn() throw (DeviceDetachException, InterfaceClaimException,
			MissingBoardException, DataWriteException);

	void setRelayOff(int relay_address) throw (DeviceDetachException,
			InterfaceClaimException, MissingBoardException,
			IncorrectRelayAddressException, DataWriteException);

	void setAllRelayOff() throw (DeviceDetachException,
			InterfaceClaimException, MissingBoardException, DataWriteException);

	void setTimerStart(int relay_address, short timer_delay)
			throw (DeviceDetachException, InterfaceClaimException,
			MissingBoardException, IncorrectRelayAddressException,
			IncorrectTimerDelayException, DataWriteException);
};

}
}
}

#endif /* K8090_H_ */
