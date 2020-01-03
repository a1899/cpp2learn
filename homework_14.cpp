// Տնային աշխատանք 14 !!!
/*
// 1. Ստեղծել դինամիկ զանգված string տիպի տարրեր պահելու համար,
//    և գտնել զանգվածի ամենաերկար բառը։

#include<iostream>
#include<string>

int* maxLength(const std::string* str, const int& size)
{
	int* index{ new int[size] {} };
	int lastIndex = 0;
	int baseLength = (int)str->length();
	int currLength = baseLength;
 	for (int i = 1; i < size; ++i)
	{
		currLength = (int)str[i].length();
		if (currLength > baseLength)
		{
			lastIndex = 0;
			index[lastIndex] = i;
			baseLength = currLength;
		}
		else if (currLength == baseLength)
		{
			++lastIndex;
			index[lastIndex] = i;
		}
	}
	index[++lastIndex] = -1;
	return index;
}

int main()
{
	std::string* sCountries = new std::string[5]{ "Belgium", "Greece", "Italy", "Albania", "Germany"};
	int* ptr = maxLength(sCountries, 5);
	std::cout << "These are the longest strings: " << '\n';
	for (int i = 0; ptr[i] >= 0; ++i)
	{
		std::cout << sCountries[ptr[i]] << " ";
	}
	delete[] sCountries;
	delete[] ptr;
}
*/

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

