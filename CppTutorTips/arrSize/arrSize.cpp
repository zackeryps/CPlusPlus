/**
* This program was written by Zackery Salzwedel
*
* The purpose of this program is to demonstrate array sizes
* and how the size is related to the indexes.
*
* This program is intended to be used by being run once
* then examining the source code.
*/

//include libraries
#include <iostream>

//use global namespace for a simple program
using namespace std;

//define global constants
const int ARR_SIZE = 9;

//define the starting point of the program
int main()
{
	//print two blank lines to separate the program output in the terminal
	cout << endl << endl;
	//declare local variabels
	int 	arr[ARR_SIZE];

	//introduce the user to the program
	cout 	<< "This program demonstrates using loops on arrays." << endl;

	cout 	<< "It is often necessary to use a loop to iterate over an entire array" << endl
		<< "A small example:" << endl;

	//set each value stored in the array to 1 then print that value
	cout 	<< endl << "Set each value stored in the array to 1 then print that value:" << endl;
	for(int i = 0; i < ARR_SIZE; i++)
	{
		cout << "assigning 1 to position " << i << endl;
		arr[i] = 1;
		cout << "arr[" << i << "]: " << arr[i] << endl;
	}
	cout << endl;

	cout	<< "It is possible to iterate over the array in reverse too:" << endl;

	//set each value stored in the array to 2 then print that value
	cout << endl << "Set each value stored in the array to 2 then print that value:" << endl;
	for(int j = ARR_SIZE-1; j >= 0; j--)
	{
		cout << "assigning 2 to position " << j << endl;
		arr[j] = 2;
		cout << "arr[" << j << "]: " << arr[j] << endl;
	}
	cout << endl;

	cout 	<< "Be careful with your index values." << endl
		<< "What is happening below and how can you prevent it?" << endl;

	//set each value stored in the array to 3 then print that value
	cout << endl << "Set each value stored in the array to 3 then print that value:" << endl;
	for(int k = ARR_SIZE; k >= 0; k--)
	{
		cout << "assigning 3 to position " << k << endl;
		arr[k] = 3;
		cout << "arr[" << k << "]: " << arr[k] << endl;
	}

	/**
	* When an array is made for size n (in this example: 9), the indexes of that array
	* are numbered 0 through n-1 (in this example: 0 through {9-1=}8)
	*
	* The final loop attempts to access the array at index number 9, which does not exist.
	* Using ARR_SIZE-1 as in the second loop ensures that the loop interates over valid indexes.
	*/

	//print two blank lines to separate the program output in the terminal
	cout << endl << endl;

	//return 0 on successful completion
	return 0;
}
