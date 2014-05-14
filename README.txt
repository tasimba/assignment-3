Author		: Tasimba Chirindo
Student Number  : CHRTAS004
Date  		: 13 May 2014
Title 		: Templates and stl specialisations
Files submtitted: CryptoMachine.h classTraits.h classPolicies.h driver.cpp tpes.h cmdline_parser.cpp cmdline_parser.h Makefile Readme testing.cpp

This program aims to make it easier and cleaner to write the code by using templates. Functors and lambda functions have been used to call the actual functions with the decoding and encoding methods.

The program is easy to compile, clean and run. The name of the executable is assignment3. To compile, type 'make' on the terminal. To run, type ./assignment3 and the user will be provided with a set of commands which when implemented will enable him/her use the encyption/decoding algorithms. To clean the binaries, type make clean.

The program is templetated by four types namely cipher, mode, group and pack. I have included a text file data.txt with a sudo line that we would want to encode. Output.txt is the text file where the encoded text is kept. The sample command prompt to encode contents of data.txt and save the results in Output.txt. The result will also be printed on the screen. Vigenere algorithm , in DR mode with  key DD will be used. Commmand prompt command is: 
./assignment3 -o output.txt -i data.txt -e -v DR -m ECB


In the files submitted, I have included the testing.cpp class. I used this class to do some unit tests on encoding and decoding using the vigenere and Xor algorithms. When run, the program passed both tests. The program cannot have two main programs, thus why i have included this file (testing.cpp) as evidence that i performed unit tests.


