// Տնային աշխատանք 14 !!!

// 1. Ստեղծել դինամիկ զանգված string տիպի տարրեր պահելու համար,
//    և գտնել զանգվածի ամենաերկար բառը։

#include<iostream>
#include<string>

int main()
{
	std::string* sCountries = new std::string[5]{ "Belgium", "Greece", "Italy", "Romaniaa", "Germany"};
	std::cout << "These are the longest strings: " << '\n';
	int baseLength = (int)sCountries->length();
	int currLength = baseLength;
	std::string longest = sCountries[0];
	for (int i = 1; i < 5; ++i)
	{
		currLength = (int)sCountries[i].length();
		if (currLength > baseLength)
		{
			baseLength = currLength;
			longest = sCountries[i];
		}
	}
	std::cout << longest;
	delete[] sCountries;
}

/*
// 2. Ստեղծել և սկզբնարժեքավորել երկչափանի դինամիկ զանգված(մատրից)։
#include <iostream>

int main()
{
	int width = 3;
	int height = 4;
	int** array = new int* [height];
	for (int i = 0; i < height; ++i)
	{
		array[i] = new int [width];
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			array[i][j] = i*width + j + 1;
			std::cout << array[i][j] << " ";
		}
		std::cout << '\n';
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << &(array[i][j]);
			std::cout << '\n';
		}
	}
	for (int i = 0; i < height; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
}
*/