#include <iostream>
#include <time.h>
#include "arrays.h"

using namespace std;

/*
Fills array with random integers
Input: arr - pointer to array, size - size of array
*/
void fill_random(int * arr, int size)
{
	//Generate new seed
	srand((unsigned)time(NULL));

	// Fill the array
	for (int i = 0; i<size; i++)
	{
		arr[i] = rand();
	}
}

/*
Prints the content of array
Input: arr - pointer to array, size - size of array
*/
void print_array(int * arr, int size)
{
	printf_s("Contents of array:\n");

	// Check if the size > 0
	if (size < 1)
	{
		printf_s("none.\n");
	}
	else
	{
		// Print all but the last
		for (int i = 0; i<size-1; i++)
		{
			printf_s("%d, ", arr[i]);
		}

		// Pretty print the last with '.' on the end
		printf_s("%d.\n", arr[size-1]);
	}
}