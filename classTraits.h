/*
* name: Tasimba Chirindo
* date: 10 May 2014
* trait class for the program. characterizes an object
*
*/


#ifndef CRYPTSTRAITS_H_
#define CRYPTSTRAITS_H_
#include "CryptoMachine.h"
#include "types.h"

namespace CHRTAS004 {
using namespace std;
template <typename cipherA,  typename mode, typename groupA, typename packA> class classTraits{
	public:
	typedef cipherA c;
	typedef groupA g;
	typedef packA p;
	typedef mode m;

	
	};

template <typename groupA, typename packA> class classTraits<vignere, mode, groupA, packA>{
public:
	typedef vignere veg;
	static string type(void) {
			return "im vignerne";
		}
};

template <typename groupA, typename packA> class classTraits<Xor, mode, groupA, packA>{
public:
	typedef Xor veg;
	static string type(void) {
			return "im Xor";
		}
};


}
#endif /* CRYPTSTRAITS_H_ */

