#ifndef CRYPTOMACHINE_H
#define CRYPTOMACHINE_H

#include "classTraits.h"
#include "classPolicies.h"
#include "types.h"
#include <iterator>
#include <iostream>
#include <vector>
#include <istream>
#include <algorithm>
#include <cctype>

using namespace std;

using namespace CHRTAS004 ;
template <typename cipher, typename grouped, typename packed, typename mode,
        typename cTraits = classTraits<cipher, grouped, packed>,
        typename cPolicies = classPolicies<cipher, grouped, packed> >

class CryptoMachine{
    public:
    typedef cipher c;
    typedef grouped g;
    typedef packed p;
    typedef mode m;

    typedef cTraits tr;
    typedef cPolicies cP;

    CryptoMachine(){
                    // default constructor
    }
    string str;
    void encode(istream & in, ostream & out){
        cPolicies::encrypt(in, out, str);
    }
    void decode(istream & in, ostream & out){
        cPolicies::decrypt(in, out, str);
    }

        virtual ~CryptoMachine(){           // destructor

        }
    };






#endif // CYPTOMACHINE_H

