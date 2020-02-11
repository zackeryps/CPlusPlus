/**
* This program was written by Zackery Salzwedel
*
* The purpose of this program is to demonstrate truthiness
* and how it can lead to logic errors.
*
* This program is intended to be used by being run once
* then examining the source code.
*/

//include libraries
#include <iostream>

//use global namespace for a simple program.
using namespace std;

//define a starting point for the program
int main()
{
	//print 2 blank lines to separate the program output in the terminal
	cout	<< endl << endl;

	//introduce the program to the user
	cout 	<< "This program demonstrates 'truth-i-ness' in c++." << endl
		<< "That is to say that all 'values', numeric or otherwise," << endl
		<< "will also be either 'true' or 'false'." << endl
		<< "In a nutshell: zero is false, not zero is true." << endl << endl;

	//zero is false
	cout	<< "Lets test using 'if(0){} else{}': " << endl;
	if(0)
	{
		cout 	<< "if(0) has evaluated to true." << endl
			<< "Program execution is currently in the 'if' part of the block" << endl
		 	<< "This should never print because the 'truthiness' of 0 is false" << endl << endl;
	}
	else
	{
		cout 	<< "if(0) has evaluated to false." << endl
			<< "Program execution is currently in the 'else' part of the block" << endl
			<< "This prints because the 'truthiness' of 0 is false" << endl << endl;
	}

	//one is true
	cout	<< "Lets test using 'if(1){} else{}': " << endl;
	if(1)
	{
		cout 	<< "if(1) has evaluated to true." << endl
			<< "Program execution is currently in the 'if' part of the block" << endl
		 	<< "This prints because the 'truthiness' of 1 is true" << endl << endl;
	}
	else
	{
		cout 	<< "if(1) has evaluated to false." << endl
			<< "Program execution is currently in the 'else' part of the block" << endl
			<< "This should never print because the 'truthiness' of 1 is true" << endl << endl;
	}

	//not zero is true
	cout	<< "Lets test using 'if(!0){} else{}': " << endl;
	if(!0)
	{
		cout 	<< "if(!0) has evaluated to true." << endl
			<< "Program execution is currently in the 'if' part of the block" << endl
		 	<< "This prints because the 'truthiness' of !0 is true" << endl << endl;
	}
	else
	{
		cout 	<< "if(!0) has evaluated to false." << endl
			<< "Program execution is currently in the 'else' part of the block" << endl
			<< "This should never print because the 'truthiness' of !0 is true" << endl << endl;
	}

	//assignment operatior returns the value that it assigns
	cout 	<< "The assignment operator (the = sign) returns what it assigns" << endl
		<< "This can lead to some hard to trace bugs." << endl << endl
		<< "Example: the variable num is initalize to zero." << endl
		<< "What happens if we try 'if(num = 0){} else{}'" << endl;
	
	//declare and initalize variables
	int num = 0;
	
	//assignment operator returns 0, and 0 is false
	if(num = 0)
	{
		cout	<< "if(num = 0) evaluated to true." << endl
			<< "Program execution is currently in the 'if' part of the block" << endl
			<< "This should never print because = returns 0 and the truthiness of 0 is false" << endl << endl;
	}
	else
	{
		cout	<< "if(num = 0) evaluated to false." << endl
			<< "Program execution is currently in the 'else' part of the block" << endl
			<< "This prints because = returns 0 and the truthiness of 0 is false" << endl << endl;
	}

	//hypothetical: while( num = 2 ){}
	cout	<< "Using what this program has demonstrated," << endl
		<< "What do you think would happen in the following code block?" << endl;

	cout	<< "while( num = 2 )" << endl
		<< "{" << endl
		<< "\t cout << num << endl" << endl
		<< "}" << endl;

	/**
	* In this example the assignment operator (the = sign) returns the value that it assigns, which is 2.
	* The truthiness of 2 is true since 2 is !0
	* Therefore our loop condition is always true, which means it is the same as writing while(true)
	* So we have an infinite loop with no output. The program would appear to stop or do nothing.
	*/

	//print 2 blanks line to separate the program output in the terminal
	cout	<< endl << endl;

	//return 0 on successful completion
	return 0;
}
