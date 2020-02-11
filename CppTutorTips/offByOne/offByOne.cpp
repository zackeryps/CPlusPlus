/*
This c++ program was written by Zackery Sazlwedel.
The purpose of this program is to demonstrate the
'off by one' error as it pertains to file reading.
This program is meant to be used by running it once,
then examining the source code.
*/
//3 steps to starting file input/output
//1. include fstream
//2. make an ofstream or ifstream variable
//2cont. o for output, i for input
//3. open() the file
//3cont. Dont forget to close() the file when finished


#include <iostream>
#include <fstream>//1. include fstream

using namespace std;

int MAX_CHAR = 20;

int main()
{
	const char filename[13] = "offByOne.txt";//size:13. 12 characters + 1 for the teminator
	char textFromFile[MAX_CHAR];//size:15. could probably get away with smaller

	cout 	<< endl << "Hello, this program will demonstrate the" << endl
		<< "'off by one' error when reading from a file" << endl << endl;
	
	cout << "To begin we will create a new file with the following data:" << endl;
	ofstream outfile;//2. make an ofstream or ifstream variable
	outfile.open(filename);//3. open the file
	outfile << "1.hello" << endl;//write a line to the file
	cout << "1.hello" << endl;//print that same line to the console
	outfile << "2.world" << endl;
	cout << "2.world" << endl;
	outfile << "3.thirdline" << endl;//the newline at the end of the file is what causes the problem
	cout << "3.thirdline" << endl;
	outfile.close();//3cont. dont forget to close() the file when finished with it.
	
	cout << endl << "Next we will use a loop to read data out of the same file" << endl;
	ifstream infile;//2. make an ofstream or ifstream variable
	infile.open(filename);//3. open the file
	if(infile.is_open())
	{
		while(!infile.eof())
		{
			infile.getline(textFromFile, MAX_CHAR);
			cout << "text from file: " << textFromFile << endl;
			//infile.peek();
		}
	}
	else
	{
		cout << "unable to open the input file." << endl;
	}
	infile.close();//3cont. dont forget to close the file when finished

	cout << endl << "Seems we have an extra line. What happened?" << endl;

	cout << endl << endl << "Lets try that again but a little bit different." << endl;
	infile.open(filename);//since we closed this file, we can open it again and reuse the variable
	if(infile.is_open())
	{
		while(!infile.eof())
		{
			infile.getline(textFromFile, MAX_CHAR);
			cout << "text from file: " << textFromFile << endl;
			infile.peek();
		}
	}
	else
	{
		cout << "unable to open the input file." << endl;
	}
	cout << endl << "What was different this time? Check the source code to find out." << endl;
	cout << endl << endl;

	/*
	When using certain methods of reading from the file the EOF or End Of File flag
	is not set when reading the last line of the file.
	In this case, infile.getline() successfully reads a full line of text fome the file.
	This is because it finds a newline character and immediately stops reading input.
	As a result of successfulling reading a full line, the EOF flag remains false
	even though we have reached the end of the file.
	Adding a call to infile.peek() means that the program will try to read input from the file
	only to realize that it is at the end of the file.
	As a result of failing to read anything, the EOF flag gets changed to true.
	*/

	return 0;
}
