/**
* This program was written by Zackery Salzwedel
*
* The purpose of this program is to demonstrate integer division
* and how it compares to floating point division.
*
* This program is intended to be used by being run once
* then examining the source code.
*/

//include libraries
#include <iostream>

//use global namespace for a simple program
using namespace std;

//define the starting point for the program
int main()
{
	//print 2 blank lines to separate the program output in the terminal window
	cout << endl << endl;
	//declare and initalize variables
	double 	intDiv = 0;//This variable will be used for integer division
	double 	fltDiv = 0;//This variable will be used for floating point division

	//introduce the program to the user
	cout 	<< "This program demonstrates how c++ handles division."
		<< endl;

	//calculate output values
	intDiv = 100/3;//This line uses integer division
	fltDiv = 100.0/3;//This line uses floating point division

	//display results
	cout 	<< "100/3 is: " << intDiv << endl;
	cout 	<< "100.0/3 is: " << fltDiv << endl;
	cout 	<< "Notice that the first line does not account for "
		<< "the '.3333'."
		<< endl;
	cout 	<< "What happened?"
		<< endl;
	/**
	* When the compiler encounters two integers as the operands for a mathematical
	* operator, it will use integer arithmatic instead of floating point arithmatic.
	* Since integers can only be whole numbers, truncation occurs at the decimal point.
	* This means that any non-whole part of the result is lost before being stored in the
	* variable named 'intDiv'.
	*
	* By including the decimal .0 in the division, the compiler
	* calculates the result using floating point arithmatic
	* instead of integer arithmatic.
	*/

	//print 2 blank lines to separate the program output in the terminal window
	cout << endl << endl;

	//return 0 on successful completion
	return 0;
}
