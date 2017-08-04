#include "Header.h"

int task2()
{
	int arraySize = 10;
	int *a = new int[arraySize];
	int *b = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		a[i] = 0 + rand() % 100;
		b[i] = 0 + rand() % 100;
	}

	PrintArray(a, arraySize);
	PrintArray(b, arraySize);

	int newArraySize = arraySize + arraySize;
	int *c = new int[newArraySize];
	for (int i = 0; i < arraySize; i++)
	{
		c[i] = a[i];
	}
	for (int i = arraySize; i < newArraySize; i++)
	{
		c[i] = b[i - arraySize];
	}
	PrintArray(c, newArraySize);
	std::cout << "Max element in array c: " << MaxElemInArray(c, newArraySize) << std::endl;

	system("pause");
	return 0;
}

void PrintArray(int *array, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << array[i];
		if (i < arraySize - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

int MaxElemInArray(int *array, int arraySize)
{
	int max = array[0];
	for (int i = 0; i < arraySize; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}