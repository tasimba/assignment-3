/*
* name: Tasimba Chirindo
* date: 10 May 2014
* driver class for the program
*
*/
#include <fstream>
#include <iostream>

#include "cmdline_parser.h"
#include "CryptoMachine.h"
#include "classTraits.h"
#include "classPolicies.h"
using namespace std;
using namespace CHRTAS004;

// Run this program to see how the cmdline_parser class works.
int main(int argc, char * argv[])
{
	// Instantiate the parser
	cmdline_parser parser;

	// Try parse command line arguments
	if(!parser.process_cmdline(argc, argv))
	{
		// Complain to the standard error stream
		parser.print_errors(cerr);
		// Follow up with help on standard output
		parser.print_help(cout);
		return 1;
	}

	// Print command line help to the standard output stream, if required
	if(parser.should_print_help())
	{
		parser.print_help(cout);
		return 0;
	}

	cout << "I should read \"" << parser.get_input_filename() << "\"" << endl;

	string filename = parser.get_input_filename();
	string outfilename = parser.get_output_filename();
	std::ifstream fin(filename.c_str());
	std::ofstream fout(outfilename.c_str());


	
	if (parser.get_encode() == true)
	{
		if (parser.check_ED_XOR() == true)
		{
			if (parser.check_group() == true)
			{
				CryptoMachine<Xor,CBC, grouped, pack> cry;
				cry.str = parser.get_ED_XOR();
				cout<<"encoding....\n";
				cry.encode(fin, fout);
				cout<<""<<endl;				
				cout<<"XOR grouping"<<endl;
				
			}
			else{
				CryptoMachine<Xor, CBC ,group, pack> cry;
				cry.str = parser.get_ED_XOR();
				cout<<"encoding....\n";
				cry.encode(fin, fout);
			}
		}		
		if (parser.check_ED_Vegenere() == true)
		{
			if (parser.check_group() == true)
			{
				CryptoMachine<vignere,ECB,grouped, pack> cry;
				cry.str = parser.get_ED_Vegenere();
				cout<<"encoding....\n";
				cry.encode(fin, fout);
				//ifstream inf(parser.get_input_filename().c_str());
				cout<<""<<endl;
				cout<<"Vegenere grouping"<<endl;

			}
			else{
				CryptoMachine<vignere, ECB,group, pack> cry;
				cry.str = parser.get_ED_Vegenere();
				cout<<"encoding....\n";
				cry.encode(fin, fout);
				
			}
		}
		
	}

	if (parser.get_decode() == true)
	{
		if (parser.check_ED_XOR() == true)
		{
			CryptoMachine<Xor, CBC, group, pack> cry;
			cry.str = parser.get_ED_XOR();
			cout<<"decoding....\n";
			cry.decode(fin, fout);
			//cout<<parser.get_ED_XOR()<<endl;
		}
		if (parser.check_ED_Vegenere() == true)
		{
			CryptoMachine<vignere, ECB, group, pack> cry;
			cry.str = parser.get_ED_Vegenere();
			cout<<"decoding....\n";
			cry.decode(fin, fout);
			
		}

	}

	if (parser.check_pack() == true)
	{
		cout<<"Packing"<<endl;
	}
	
	return 0;
}
