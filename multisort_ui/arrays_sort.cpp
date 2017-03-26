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
Input: arr - pointer to array, size - size of array, from - starting position
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

// Quicksort

/*
Sorts the subarray using quick-sort method
Input: arr - pointer to array, start - starting position, end - ending position
*/
void sort_quick(int * arr, int start, int end)
{
	// Array size not less than 2
	if (end - start > 0)
	{
		// Find pivot
		int pivot = find_pivot(arr, start, end);
		// Place left on first position, right on last poition
		int left = start, right = end;

		// While they don't cross
		while (left < right)
		{
			// Shift left until number more ore equal to pivot found
			while (arr[left] < pivot) left++;
			// Shift right until number less than pivot found
			while (arr[right] >= pivot) right--;
			// Swap if needed
			if (left < right) swap(arr[left], arr[right]);
		}

		// Place left on second pos (subarray size should be cut by 1 at least)
		left = start + 1;
		// Shift until pivot reached
		while (arr[left] < pivot) left++;

		// Sort arrays on the left and on the right of pivot
		sort_quick(arr, start, left - 1);
		sort_quick(arr, left, end);
	}
}

/*
Finds pivot in subarray
Input: arr - pointer to array, start - starting position, end - ending position
Output: resulting pivot
*/
int find_pivot(int * arr, int start, int end)
{
	// Take the first number as minimum and maximum
	int min = arr[start], max = arr[start];
	// Go through array and change minimum and maximum if needed
	for (int i = start; i <= end; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	// Find and return the pivot
	return (min + max) / 2;
}

// Heapsort

/*
Sorts the array using heap-sort method
Input: arr - pointer to array, size - array size
*/
void sort_heap(int * arr, int size)
{
	for (int pos = size - 1; pos > 0; pos--)
	{
		// Make heap from given array
		build_heap(arr, pos + 1);
		// Swap the last and the first. Exclude last and continue
		swap(arr[0], arr[pos]);
	}
}

/*
Builds a heap from given array
Input: arr - pointer to array, size - size of array
*/
void build_heap(int * arr, int size)
{
	// Go from bottom to top (exclude lower level)
	for (int head = size / 2 - 1; head >= 0; head--)
	{
		// Swap flag to exclude explicit checks
		bool swapped = true;
		// Take subtree
		int sub = head;
		while (sub * 2 + 1 < size && swapped)
		{
			// Take child
			int child = sub * 2 + 1;
			// If right child exists and bigger - take it instead
			if (child + 1 < size && arr[child] < arr[child + 1])
			{
				child++;
			}
			// Swap the head with a child if necessary and continue with branch
			if (arr[sub] < arr[child])
			{
				swap(arr[sub], arr[child]);
				sub = child;
			}
			else
			{
				// If no swaps - subtree is heap already
				swapped = false;
			}
		}
	}
}