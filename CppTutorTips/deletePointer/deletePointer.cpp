//include libraries
#include <iostream>
#include <cstring>

/**
* This program was written by Zackery Salzwedel
*
* The purpose of this program is to demonstrate memory deallocation
* and how it impacts pointers to that memory
*
* This program is intended to be used by being run once
* then examining the source code.
*/

//use global namespace for a simple program
using namespace std;

//define global constants
const int STR_MAX = 99;

//define a starting point for the program
int main()
{
	//define local variables
	char* strName = new char[STR_MAX];
	char* strNull = nullptr;
	
	//copy data into variable
	strcpy(strName, "Alan Turning");

	//print two blank lines to separate program output in the terminal
	cout	<< endl << endl;

	//output results
	cout	<< "C++ handles pointers similar to how it handles truth-i-ness" << endl
		<< "That is to say: zero(null) is false and not zero is true" << endl
		<< "Since C-Strings are pointers, the same logic applies." << endl
		<< endl;

	cout	<< "Let us see what happens with two variables:" << endl
		<< "strName points to a name" << endl
		<< "strNull is set to nullptr" << endl
		<< endl;

	if(strName) //if(strName != nullptr)
	{
		cout	<< "if(strName) has evaluated to true" << endl
			<< "This prints because a pointer that is not nullptr is 'true'" << endl;
	}
	else
	{
		cout 	<< "if(strName) has evaluated to false" << endl
			<< "This should never print because a pointer that is not nullptr is 'true'" << endl;
	}
	
	cout << endl;

	if(strNull) //if(strNull != nullptr)
	{
		cout	<< "if(strNull) has evaluated to true" << endl
			<< "This should never print because a pointer that is not nullptr is 'true'" << endl;
	}
	else
	{
		cout	<< "if(strNull) has evaluated to false" << endl
			<< "This prints because a pointer that is not nullptr is 'true'" << endl;
	}

	cout	<< endl 
		<< "Since C-Strings are manually allocated, they must be manually deallocated" << endl
		<< "Using 'delete' does not change the value of the pointer, however." << endl
		<< "What does this mean for the truth-value of the pointer?" << endl
		<< endl;

	cout	<< "The next lines of code are:" << endl
		<< "delete [] strName;" << endl
		<< "if(strName){...} else{...}" << endl;

	//deallocate memory
	delete [] strName;

	if(strName)//if(strName != nullptr)
	{
		cout 	<< "Which section of the conditional is program execution printing this text from?" << endl
			<< "The 'if' section or the 'else' section?" << endl
			<< "In other words, after deleting strName, is strName true or false?" << endl;
	}
	else
	{
		cout 	<< "Which section of the conditional is program execution printing this text from?" << endl
			<< "The 'if' section or the 'else' section?" << endl
			<< "In other words, after deleting strName, is strName true or false?" << endl;
	}

	/**
	* When manually deallocating memory using the 'delete' keyword the value
	* of the pointer does not change. Thus the pointer then points to memory
	* that the program no longer has access to. This means that the pointer
	* is considered 'true' since it is not equal to null after calling delete on it.
	* To prevent logic errors from happening, set the pointer = nullptr after deletion.
	*/

	//print two blank lines to separate program output in the terminal
	cout	<< endl << endl;

	//return 0 on successful completion
	return 0;
}
