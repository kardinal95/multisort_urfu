#include <iostream>
#include "arrays_sort.h"

using namespace std;

// Bubblesort

/*
Sorts the array using bubble algorithm.
Input: arr - pointer to array, size - size of array
*/
void sort_bubble(int * arr, int size)
{
	// Take each subarray (from biggest to smallest)
	for (int sub = size; sub > 1; sub--)
	{
		// Go from the last to the second position of subarray
		for (int pos = size - 1; pos > size - sub; pos--) {
			if (arr[pos - 1] > arr[pos])
			{
				// Swap elements if previous is bigger
				swap(arr[pos - 1], arr[pos]);
			}
		}
	}
}

// Shellsort

/*
Sorts the array using shell algorithm.
Input: arr - pointer to array, size - size of array
*/
void sort_shell(int * arr, int size)
{
	// First make the array with sizes of gaps
	// Get the size
	int gap_sizes = get_gaps_size(size);
	// Create and fill with gap sizes
	int * seq = get_gaps(gap_sizes);

	// Sort every subarray using insert sort
	for (int current = gap_sizes - 1; current >= 0; current--)
	{
		int gap = seq[current];
		for (int sub = 0; sub < gap; sub++)
		{
			sort_insert(arr, size, sub, gap);
		}
	}

}

/*
Finds all the needed gaps for sorting array using shell algorithm
Input: size - size of array ot be sorted
Output: pointer to array containing found gaps
*/
int * get_gaps(int size)
{
	int * seq = new int[size];
	for (int i = 0; i < size; i++)
	{
		seq[i] = get_gap(i);
	}
	return seq;
}

/*
Finds gap length for shell sort using Sedgewick formula
Input: i - number of step in shell sort
Output: gap_length - resulting length
*/
int get_gap(int i)
{
	int gap_length;
	if (i % 2 == 0)
	{
		gap_length = (int)(9 * pow(2.0, i) - 9 * pow(2.0, i / 2) + 1);
	}
	else
	{
		gap_length = (int)(8 * pow(2.0, i) - 6 * pow(2.0, (i + 1) / 2) + 1);
	}
	return gap_length;
}

/*
Finds the size of array for storing gap sizes for shell algorithm
Input: size - size of array to be sorted
Output: int containing size of array for storing gaps
*/
int get_gaps_size(int size)
{
	// Base size
	int gaps_len = 1;
	int step = 0;
	int next = get_gap(step + 1);
	// Stop when exceeds effective size
	while (next * 3 <= size)
	{
		step++;
		gaps_len++;
		next = get_gap(step + 1);
	}
	return gaps_len;
}

// Insertsort

/*
Sorts the subarray of the array depending on step
Input: arr - pointer to array, size - size of array,
step - gap between elements in subarray (1 sorts all the array)
*/
void sort_insert(int * arr, int size, int from, int step)
{
	int buffer;

	// Do steps until the end of array
	for (int start = from; start < size; start += step)
	{
		// Place current element in buffer
		buffer = arr[start];
		// Check all previous elemenets (by used step)
		for (int pos = start - step; pos >= from; pos -= step)
		{
			// Shift the current element to next position if bigger than buffer
			if (arr[pos] > buffer)
			{
				arr[pos + step] = arr[pos];
				// If reached start and haven't placed buffer back - place on the first position
				if (pos == from)
				{
					arr[pos] = buffer;
				}
			}
			// If less - position found, place the number from buffer after the current element
			else
			{
				arr[pos + step] = buffer;
				// Stop the cycle because buffer is placed
				break;
			}
		}
	}
}

// Quicksort (broken!)

void sort_quick(int * arr, int start, int end)
{
	if (end - start > 0)
	{
		int pivot = find_pivot(arr, start, end);
		int left = start, right = end;

		while (left < right)
		{
			while (arr[left] < pivot) left++;
			while (arr[right] > pivot) right--;
			if (left < right) swap(arr[left], arr[right]);
		}

		left = start;
		while (arr[left] < pivot) left++;

		sort_quick(arr, start, left - 1);
		sort_quick(arr, left, end);
	}
}

int find_pivot(int * arr, int start, int end)
{
	int min = arr[start], max = arr[start];
	for (int i = start; i <= end; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	return (min + max) / 2;
}