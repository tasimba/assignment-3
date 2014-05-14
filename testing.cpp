/*
* name       : Tasimba Chirindo
* date       : 10 May 2014
* Unit Testing class , to check if the program is doing successful encoding/decoding
*
*/

#include "CryptoMachine.h"
#include <algorithm>
#include <iostream>		// I/O streams Header
#include <string>		// Strings Header
#include <random>		// For random number generation
#include <chrono>		// For accessing the system clock

#define CATCH_CONFIG_MAIN // So that Catch will define a main method
#include "catch.hpp"     // Catch unit testing framework

#define UNIT_TESTING     // So that we know whether to include our counter class
#include "counter.h"     // Object counter header


using namespace std;

TEST_CASE("vigenere","")
{
using namespace CHRTAS004;

CryptoMachine<vignere,ECB,grouped, pack> A ;
SECTION("TESTING ENCODING")
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	A.encode(fin,fout);
	fin.close();
	fout.close();
}
SECTION("TESTING DECODING")
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	A.decode(fin,fout);
	fin.close();
	fout.close()
}

}

TEST_CASE("xor","")
{
using namespace CHRTAS004;

CryptoMachine<Xor,CBC,grouped, pack> B ;
SECTION("TESTING ENCODING")
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	B.encode(fin,fout);
	fin.close();
	fout.close();
}
SECTION("TESTING DECODING")
{
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	B.decode(fin,fout);
	fin.close();
	fout.close()
}

}






	



