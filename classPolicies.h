/*
* name: Tasimba Chirindo
* date: 10 May 2014
* policy class for the program . characterizes behaviour of the class / class object
*
*/

#ifndef CRYPTSPOLICIES_H_
#define CRYPTSPOLICIES_H_
#include "classTraits.h"
#include "CryptoMachine.h"
#include "types.h"
#include <iterator>
#include <algorithm>
#include <cctype>
#include <istream>
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;
namespace CHRTAS004 {
template <typename cipher, typename mode, typename group, typename pack> class classPolicies{
	public:
	typedef cipher c;
	typedef group g;
	typedef pack p;
	typedef mode m;
	static void encrypt(istream & in, ostream & out, string s){};
	};

//----------------------------------------------------------------------------------------

class encodeFunctorVignere{
private:
	std::string key;
	unsigned int pos;

public:
	encodeFunctorVignere(const std::string& key2) : key(key2), pos(0) {

	}
	char operator ()(char ch) {
		ch = toupper(ch);
		return (((ch - 'A') + (key[pos++ % key.size()]- 'A')) % 26) + 'A';
	}
};


//------------------------------------------------------------------------------------------------------------

class decodeFunctorVignere{
private:
	std::string key;
	unsigned int pos;

public:

	decodeFunctorVignere(const std::string& key2) : key(key2), pos(0) {

	}
	char operator ()(char ch) {
		int check = (((ch - 'A') - (key[pos++ % key.size()]- 'A')) % 26);
		if(check < 0){
			check +=26;
		}
		//ch = toupper(ch);
		return check + 'A';
	}
};

template <typename pack> class classPolicies<vignere, ECB, grouped, pack>{
	public:
		static void encrypt(istream & in, ostream & out, string s){

			string key = s;

			vector<string> list;
			vector<string> encodedList;
			std::copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(list));
			string conc = "";

			for (string &s : list){
				conc += s;
				
			}

			string encoded;
			int count = 0;
			cout << "testing" << endl;
			std::transform(conc.begin(), conc.end(), back_inserter(encoded), encodeFunctorVignere(s));
			for (char &s : encoded){
				if (isalpha(s)){
					count++;
					out<<s;
					cout<<s;
					if(count % 5 == 0){
						out<< " ";
						cout<< " ";
						count = 0;
					}
				}
			}	
		}
};

//------------------------------------------------------------------------------------------------

template <typename group, typename pack> class classPolicies<vignere, ECB, group, pack>{
	public:
		static void encrypt(istream & in, ostream & out, string s){

			string key = s;

			vector<string> list;
			vector<string> encodedList;
			std::copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(list));
			vector<string>::iterator i;

			string conc = "";

			for (string &s : list){
				conc += s;
			}

			string encoded;
			cout << "testing" << endl;
			std::transform(conc.begin(), conc.end(), back_inserter(encoded), encodeFunctorVignere(s));
			cout << encoded << endl;
			out<<encoded<<endl;
		}

		static void decrypt(istream & in, ostream & out, string s){

			string key = s;

			vector<string> list;
			vector<string> encodedList;
			std::copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(list));
		
			vector<string>::iterator i;
			
			string conc = "";

			for (string &s : list){
				conc += s;
				//out<<s;
				//cout<<s;
			}

			string encoded(conc.size(), '\0');
			cout << "testing" << endl;
			std::transform(conc.begin(), conc.end(), back_inserter(encoded), decodeFunctorVignere(s));
			cout << encoded << endl;
			out<<encoded<<endl;
			//cout << "testing 2" << endl;
		}
	};


//----------------------------------------------------------------------------------------------------------------------------------

template <typename pack> class classPolicies<Xor, CBC, grouped, pack>{
	public:
		static void encrypt(istream & in, ostream & out, string s){

			int32_t key = 0;

			stringstream(s) >> key;
			vector<char> list;
			vector<char> encodedList;
			std::copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(), back_inserter(list));
			std::transform(list.begin(), list.end(), back_inserter(encodedList), [key](char value){return ((int32_t)value)^key;});
			/*for (i = list.begin(); i != list.end();i++){
				cout << *(i);
			}*/
			int count = 0;
			for (char &s : encodedList){
				if (isalpha(s)){
					count++;
					out<<s;
					cout<<s;
					if(count % 5 == 0){
						out<< " ";
						cout<<s;
						count = 0;
					}
				}

				//cout<<s;
			}
			cout<<endl;
		}
};



//----------------------------------------------------------------------------------------------------------------------------------------------

template <typename group, typename pack> class classPolicies<Xor, CBC, group, pack>{
	public:
		static void encrypt(istream & in, ostream & out, string s){

			int32_t key = 0;

			stringstream(s) >> key;
			vector<char> list;
			vector<char> encodedList;
			std::copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(), back_inserter(list));
			std::transform(list.begin(), list.end(), back_inserter(encodedList), [key](char value){return ((int32_t)value)^key;});
			vector<char>::iterator i;
			/*for (i = list.begin(); i != list.end();i++){
				cout << *(i);
			}*/
			for (char &s : encodedList){
				out<<s;
				cout<<s;
			}
			cout<<endl;
		}

		static void decrypt(istream & in, ostream & out, string s){

			int32_t key = 0;

			stringstream(s) >> key;
			vector<char> list;
			vector<char> decodedList;
			std::copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(), back_inserter(list));
			std::transform(list.begin(), list.end(), back_inserter(decodedList), [key](char value){return ((int32_t)value)^key;});
			vector<char>::iterator i;
			
			for (char &s : decodedList){
				out<<s;
				cout<<s;
			}
		}

	};

//------------------------------------------------------------------------------------------------------------------

}
#endif /* CRYPTSPOLICIES_H_ */

