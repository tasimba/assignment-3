#ifndef CMDLINE_PARSER_H_

#define CMDLINE_PARSER_H_

#include <iostream>
#include <list>
#include <string>

#include <boost/program_options.hpp>
namespace CHRTAS004{
//---------------------------------------------------------------------------//
class cmdline_parser
{
public:
    //-----------------------------------------------------------------------//
	// Constructor
	cmdline_parser(void);

	// Member function that parses command line options
	bool process_cmdline(int argc, char * argv[]);
	// Return the input filename
	std::string get_input_filename(void) const;
	// Return the output filename
	std::string get_output_filename(void) const;

	// Checks if user supplied the proper args
	bool get_encode(void);
	bool get_decode(void);
	bool check_ED_XOR(void);
	bool check_ED_Vegenere(void);
	bool check_group(void);
	bool check_pack(void);
	bool check_mode(void);

	// Returns the user supplied args
	std::string get_ED_XOR(void) const;
	std::string get_ED_Vegenere(void) const;

	void print_errors(std::ostream & out) const;

	bool should_print_help(void) const;
	// Output help to the specified output stream
	void print_help(std::ostream & out) const;

private:
    //-----------------------------------------------------------------------//
	// Member variables
	boost::program_options::variables_map vm;
	boost::program_options::options_description od;
	std::list<std::string> errors;

    //-----------------------------------------------------------------------//
	// Static string variables
	static const std::string INPUTFILE;
	static const std::string OUTPUTFILE;
	static const std::string encode;
	static const std::string decode;
	static const std::string ED_XOR;
	static const std::string mode;
	static const std::string init;
	static const std::string ED_Vigenere;
	static const std::string group;
	static const std::string packing;

};
}
#endif /* CMDLINE_PARSER_H_ */
