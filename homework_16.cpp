
// 1. Given an array, rotate the array to the right 
//    by k steps, where k is non-negative.

#include <iostream>

void rotate(int* arr, const int& arrSize, const int& steps)
{
	int k = steps % arrSize;
	if (k == 0)
	return;
	else
	{
		int temp = 0;
		for (int i = 0; i < k; ++i)
		{
			for (int oddIndex = 1, evenIndex = 2; oddIndex < arrSize; oddIndex += 2, evenIndex += 2)
			{
				temp = arr[oddIndex];
				arr[oddIndex] = arr[0];
				if (evenIndex == arrSize)
				{
					arr[0] = temp;
					break;
				}
				arr[0] = arr[evenIndex];
				arr[evenIndex] = temp;
			}
		}
		return;
	}
}

int main()
{
	int size = 8;
	int* arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i + 1;
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
	rotate(arr, size, 11
	);
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
}

/*
// 2. Implement pow(x,n), which calculates x raised to the power n (x^n).
//    Note: -100.0 < x < 100.0,
//          n is a 32-bit signed integer, whitin the range [2^-31, 2^31 - 1].

#include <iostream>

inline double mult(const double& input, const int& pow)
{
	if (pow == 1)
		return input;
	else
		return input * mult(input, pow - 1);
}

double power(const double& x, int n)
{
	if (n > 0)
		return mult(x, n);
	else if (n == 0)
		return 1;
	else
	{
		n *= -1;
		return (1 / mult(x, n));
	}
}

int main()
{
	std::cout << power(2, 99);
}
*/
/*
// 3. Given an integer, convert it to a Roman numeral. Input
//    is guaranteed to be within the range from 1 to 3999.

#include <iostream>

void convert(char* arr, const int& digit, const int& digitWeight, int& nextElement);

char* romanNumerals(int input)
{
	int digits[4]{};
	int digitCount = 0;
	while (input != 0)
	{
		digits[digitCount] = input % 10;
		input /= 10;
		++digitCount;
	}
	char* romanSymols = new char[16]{}; // max possible num of symbols in case of 3888, including null
	int nextElement = 0;
	for (int i = digitCount - 1; i >= 0; --i)
	{
		convert(romanSymols, digits[i], i, nextElement);
	}
	return romanSymols;
}

void convert(char* arr, const int& digit, const int& digitWeight, int& nextElement)
	{
		char c1, c5, c10;
		switch (digitWeight)
		{
		case 0:
			c1 = 'I'; c5 = 'V'; c10 = 'X';
			break;
		case 1:
			c1 = 'X'; c5 = 'L'; c10 = 'C';
			break;
		case 2:
			c1 = 'C'; c5 = 'D'; c10 = 'M';
			break;
		case 3:
			c1 = 'M'; c5 = '\0'; c10 = '\0';
			break;
		default:
			std::cout << "Invalid input !";
		}
		switch (digit)
		{
		case 0:
			break;
		case 1:
			arr[nextElement] = c1;
			++nextElement;
			break;
		case 2:
			arr[nextElement] = c1;
			arr[++nextElement] = c1;
			++nextElement;
			break;
		case 3:
			arr[nextElement] = c1;
			arr[++nextElement] = c1;
			arr[++nextElement] = c1;
			++nextElement;
			break;
		case 4:
			arr[nextElement] = c1;
			arr[++nextElement] = c5;
			++nextElement;
			break;
		case 5:
			arr[nextElement] = c5;
			++nextElement;
			break;
		case 6:
			arr[nextElement] = c5;
			arr[++nextElement] = c1;
			++nextElement;
			break;
		case 7:
			arr[nextElement] = c5;
			arr[++nextElement] = c1;
			arr[++nextElement] = c1;
			++nextElement;
			break;
		case 8:
			arr[nextElement] = c5;
			arr[++nextElement] = c1;
			arr[++nextElement] = c1;
			arr[++nextElement] = c1;
			++nextElement;
			break;
		case 9:
			arr[nextElement] = c1;
			arr[++nextElement] = c10;
			++nextElement;
			break;
		default:
			std::cout << "Invalid input !";
		}
	}

int main()
{
	char* roman = romanNumerals(3888);
	std::cout<< "The Roman version of 3888 is: " << roman;
	delete[] roman;
}
*/