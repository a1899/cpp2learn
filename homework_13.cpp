// Տնային աշխատանք 13 !!!

// 1. Պարզել, տրված c բնական թվի համար կան արդյոք 
//    a և b բնական թվեր այնպիսին, որ a ^ 2 + b ^ 2 = c

#include <iostream>

// theorem "An integer greater than one can be written as a 
// sum of two squares if and only if its prime decomposition 
// contains no prime congruent to 3 modulo 4 raised to an odd power."

bool sumOf2Sqrs(int input)
{
	int exponent = 0;
	for (int divisor = 2; divisor <= input / divisor; ++divisor)
	{
		while (!(input % divisor)) // when the loop is over, max power of the current prime factor is found
		{
			++exponent;
			input /= divisor;
		}
		if ((exponent != 0) && (divisor % 4 == 3) && (exponent % 2))
			return false;
		else // the next value of "divisor" that will divide the current value of "input" will always be prime
			exponent = 0;
	}
	if (input % 4 == 3) // when the loop is over, either the last prime factor or 1 is the value of "input"
		return false;
	else
		return true;
}

int main()
{
	if (sumOf2Sqrs(3430))
		std::cout << "Input number can be written as a sum of two squares";
	else
		std::cout << "Input number can't be written as a sum of two squares";
}

/*
// 2. Իրականացնել strstr() ֆունկցիան

#include <iostream>
#include <cstring>

const char* strst(const char* str1, const char* str2)
{
	int checkLimit = std::strlen(str1) - std::strlen(str2);
	if (checkLimit < 0)
		return nullptr;
	else
	{
		int strLen = std::strlen(str2);
		int counter = 0;
		for (const char* p = str1; p != str1 + checkLimit + 1; ++p)
		{
			for (int i = 0; (p[i] == str2[i]) && (i < strLen); ++i)
				++counter;
			if (counter == strLen)
				return p;
			counter = 0;
		}
		return nullptr;
	}
}

int main()
{
	char myString [] = "A sample string";
	const char* p = strst(myString, "sample");
	if (p)
		std::cout << p;
	else
		std::cout << "Null pointer returned.";
}
*/