#include "cmdline_parser.h"
using namespace CHRTAS004;
//-------------------------------------------------------------------------//
// Constructor, initialise the variables_map object with default
// constructor, options_descriptor with the name "Options"
//-------------------------------------------------------------------------//
cmdline_parser::cmdline_parser(void) : vm(), od("Options")
{
	// Shorter alias for the boost::program_options namespace
	namespace po = boost::program_options;

	// Add two cmdline options
	// --help or -?
	// --input-file or -i
	od.add_options()
		("help,?", "produce help message")
				((INPUTFILE+",i").c_str(), po::value<std::string>(),
					"input file name")
				((OUTPUTFILE+",o").c_str(), po::value<std::string>(),
					"output file name")
				((encode+",e").c_str(),"encoding")
				((init+",I").c_str(), "Use the provided initialisation vector when in CBC mode.")
				((ED_XOR+",x").c_str(), po::value<std::string>(),"Encode/Decode with XOR cipher with specified key.")
				((decode+",d").c_str(),"decoding")
				((mode+",m").c_str(), "mode")
				((ED_Vigenere+",v").c_str(), po::value<std::string>(),"Encode/Decode with Vigenere cipher with specified key.")
				((group+",g").c_str(),"Specify support for grouping into code blocks")
				((packing+",p").c_str(),"Specify support for bit packing");
};

//-------------------------------------------------------------------------//
// Process the cmdline
//-------------------------------------------------------------------------//
bool cmdline_parser::process_cmdline(int argc, char * argv[])
{
	// Shorter alias for the boost::program_options namespace
		namespace po = boost::program_options;

		// Clear the variable map
		vm.clear();

		// Parse the cmdline arguments defined by argc and argv,
		// looking for the options defined in the od variable,
		// and store them in the vm variable.
		po::store(po::parse_command_line(argc, argv, od), vm);
		po::notify(vm);

		bool success = true;

		if(vm.count(INPUTFILE) == 0)
		{
			success = false;
			errors.push_back(
				INPUTFILE + " not specified.");
		}

		if(vm.count(OUTPUTFILE) == 0)
		{
				success = false;
				errors.push_back(
					OUTPUTFILE + " not specified.");
		}

		return success;
}

//-----------------------------------------------------------------------//
// Return the input PGM filename
//-------------------------------------------------------------------------//
std::string cmdline_parser::get_input_filename(void) const
{
	// Return whatever value is stored as a string
	return vm[INPUTFILE].as<std::string>();
}

//-----------------------------------------------------------------------//
// Return the darkening output PGM filename
//-------------------------------------------------------------------------//
std::string cmdline_parser::get_output_filename(void) const
{
	// Return whatever value is stored as a string
	return vm[OUTPUTFILE].as<std::string>();
}

bool cmdline_parser::get_encode(void)
{
	return vm.count(encode) > 0;
}

bool cmdline_parser::get_decode(void)
{
	return vm.count(decode) > 0;
}

bool cmdline_parser::check_mode(void)
{
	return vm.count(mode) > 0 ; }


bool cmdline_parser::check_ED_XOR(void)
{
	return vm.count(ED_XOR) > 0;
}

std::string cmdline_parser::get_ED_XOR(void) const
{
	return vm[ED_XOR].as<std::string>();
}

bool cmdline_parser::check_ED_Vegenere(void)
{
	return vm.count(ED_Vigenere) > 0;
}

std::string cmdline_parser::get_ED_Vegenere(void) const
{
	return vm[ED_Vigenere].as<std::string>();
}


bool cmdline_parser::check_group(void)
{
	return vm.count(group) > 0;
}

bool cmdline_parser::check_pack(void)
{
	return vm.count(packing) > 0;
}
//-----------------------------------------------------------------------//
// Should we print cmdline help?
//-------------------------------------------------------------------------//
bool cmdline_parser::should_print_help(void) const
{
	// Are there instances of the help option stored in the variable map
	return vm.count("help") > 0;
}

//-------------------------------------------------------------------------//
// Print out the options_descriptor to the supplied output stream
//-------------------------------------------------------------------------//
void cmdline_parser::print_help(std::ostream & out) const
{
	out << od;
}

//-------------------------------------------------------------------------//
// Print out the options_descriptor to the supplied output stream
//-------------------------------------------------------------------------//
void cmdline_parser::print_errors(std::ostream & out) const
{
	std::cerr << "Error processing command line arguments:" << std::endl;
	std::copy(errors.begin(), errors.end(),
		std::ostream_iterator<std::string>(out, "\n"));
}

// Definition of static strings in the class
const std::string cmdline_parser::INPUTFILE = "input-file";
const std::string cmdline_parser::OUTPUTFILE = "output-file";
const std::string cmdline_parser::encode = "encode";
const std::string cmdline_parser::decode = "decode";
const std::string cmdline_parser::ED_XOR = "xor";
const std::string cmdline_parser::init = "initilization vector";
const std::string cmdline_parser::mode = "mode";
const std::string cmdline_parser::ED_Vigenere = "vigenere";
const std::string cmdline_parser::group = "group";
const std::string cmdline_parser::packing = "pack";



