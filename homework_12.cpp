//Տնային աշխատանք 12 !!!!

// 1. Make file with "append" mode, write some text into file and close it.
//    Then reopen it, read content and store in string object.

#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string buffer;
	std::fstream myFile("file.txt", std::ios::out | std::ios::app);
	if (myFile.is_open())
	{
		myFile << "Make file with \"append\" mode,\nwrite some text into file \nand close it.";
	}
	else
		std::cout << "Failed to open a file.";
	myFile.close();
	myFile.open("file.txt", std::ios::in);
	if (myFile.is_open())
	{
		std::getline(myFile, buffer);
	}
	myFile.close();
	std::cout << buffer;
}

/*
// 2. Just create file in your PC, write sequence of numbers.
//    Then from your program make file(associated with that file), 
//    and make array by reading numbers from file.

#include <iostream>
#include <fstream>

int main()
{
	int seq[9];
	std::ifstream file("sequence.txt");
	if (file.is_open())
	{
		for (int i = 0; i < 9; ++i)
		{
			file >> seq[i];
		}
	}
	else
		std::cout << "Failed to open the file.";
	file.close();
	for (int i : seq)
	{
		std::cout << i << '\n';
	}
}
*/
/*
// 3. Convert integer and double to std::string using stringstream class.

#include <iostream>
#include <sstream>
#include <string>

int main()
{
	std::string strInt;
	std::string strDouble;
	int a = 4;
	double b = 6.98;
	std::stringstream ss;
	ss << a;
	strInt = ss.str();
	ss.str(std::string());
	ss << b;
	strDouble = ss.str();
	std::cout << strInt << '\n' << strDouble;
	ss.str(std::string());
	ss << strInt;
	ss >> b;
	std::cout << '\n' << b;
}
*/