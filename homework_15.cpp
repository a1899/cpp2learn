
// 1. Given a matrix of m x n elements (m rows, n columns),
//    return all elements of the matrix in spiral order.

#include <iostream>

void spiral(int** arr, const int& width, const int& height)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int w;
	int h;
	for (;;)
	{
		w = width - 1 - k;
		h = height - 1 - k;
		for (; j < w; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		if (!(i < h))
			break;
		for (; i < h; ++i)
		{
			std::cout << arr[i][j] << " ";
		}
		if (!(j > k))
			break;
		for (; j > k; --j)
		{
			std::cout << arr[i][j] << " ";
		}
		++k;
		if (!(i > k))
			break;
		for (; i > k; --i)
		{
			std::cout << arr[i][j] << " ";
		}
	}
	std::cout << arr[i][j] << " ";
}

int main()
{
	int h = 5;
	int w = 7;
	int** arr = new int* [h];
	for (int i = 0; i < h; ++i)
	{
		arr[i] = new int[w];
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			arr[i][j] = i * w + j + 1;
			std::cout << arr[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	spiral(arr, w, h);
	for (int i = 0; i < h; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

/*
// 2. Given an unsorted intiger array, find the smallest missing positive integer.
#include <iostream>

int main()
{
	const int size = 15;
	int* randArr = new int[size]{ -4,6,16,98,1,-12,2,3,14,65,4,-78,5,23,7 };
	int* cache = new int[size]{};
	for (int i = 0; i < size; ++i)
	{
		if ((randArr[i] > 0) && (randArr[i] <= size))
		{
			cache[randArr[i] - 1] = randArr[i];
		}
	}
	delete[] randArr;
	int missing = 1;
	if (cache[0] != 0)
	{
		for (int i = 0; i < size; ++i)
		{
			if (i == size - 1)
			{
				missing = size + 1;
				break;
			}
			else if (cache[i + 1] == 0)
			{
				missing = ++cache[i];
				break;
			}
		}
	}
	delete[] cache;
	std::cout << "The smallest missing number is: " << missing;
}
*/
/*
// 3. You are given an  n x n  2D matrix representing an image.
//    Rotate the image by 90 degrees (clockwise).
//    Note: You have to rotate the image in-place, which means
//    You have to modify the input 2D matrix directly. DO NOT 
//    allocate another 2D matrix and do the rotation.

#include<iostream>

void rotate(int** square, const int& side)
{
	int temp1 = 0;
	int temp2 = 0;
	int i = 0;
	int j = 0;

	for (int topSide = 0, k = 1; topSide <= (side - 1) / 2; ++topSide, k += 2) 
	{
		int bottomSide = side - 1 - topSide;
		int& rightSide = bottomSide;
		int& leftSide = topSide;
		for (int offset = 0; offset < side - k; ++offset) 
		{
			i = topSide; j = leftSide + offset;
			temp1 = square[i][j];
			i = topSide + offset; j = rightSide;
			temp2 = square[i][j];
			square[i][j] = temp1;
			i = bottomSide; j = rightSide - offset;
			temp1 = square[i][j];
			square[i][j] = temp2;
			i = bottomSide - offset; j = leftSide;
			temp2 = square[i][j];
			square[i][j] = temp1;
			i = topSide; j = leftSide + offset;
			square[i][j] = temp2;
		}
	}
}

int main()
{
	int size = 4;
	int** sqArray = new int*[size];
	for (int i = 0; i < size; ++i)
	{
		sqArray[i] = new int[size];
	}
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			sqArray[i][j] = i*size + j + 1;
			std::cout << sqArray[i][j] << " ";
		}
		std::cout << '\n';
	}
	rotate(sqArray, size);
	std::cout << '\n' << '\n';
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << sqArray[i][j] << " ";
		}
		std::cout << '\n';
	}
	for (int i = 0; i < size; ++i)
	{
		delete[] sqArray[i];
	}
	delete[] sqArray;
}
*/
