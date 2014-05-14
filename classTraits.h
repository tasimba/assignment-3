
#ifndef CRYPTSTRAITS_H_
#define CRYPTSTRAITS_H_
#include "CryptoMachine.h"
#include "types.h"

namespace CHRTAS004 {
using namespace std;
template <typename cipherA, typename groupA, typename packA, typename moDe> class classTraits{
	public:
	typedef cipherA c;
	typedef groupA g;
	typedef packA p;
	typedef moDe m;

	
	};

template <typename groupA, typename packA> class classTraits<vignere, groupA, packA, moDe>{
public:
	typedef vignere veg;
	static string type(void) {
			return "im vignerne";
		}
};

template <typename groupA, typename packA> class classTraits<Xor, groupA, packA, moDe>{
public:
	typedef Xor veg;
	static string type(void) {
			return "im Xor";
		}
};


}
#endif /* CRYPTSTRAITS_H_ */

