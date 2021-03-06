#pragma once

// Bubblesort

/*
Sorts the array using bubble algorithm.
Input: arr - pointer to array, size - size of array
*/
void sort_bubble(int * arr, int size);

// Shellsort

/*
Sorts the array using shell algorithm.
Input: arr - pointer to array, size - size of array
*/
void sort_shell(int * arr, int size);

/*
Finds all the needed gaps for sorting array using shell algorithm
Input: size - size of array ot be sorted
Output: pointer to array containing found gaps
*/
int * get_gaps(int size);

/*
Finds gap length for shell sort using Sedgewick formula
Input: i - number of step in shell sort
Output: gap_length - resulting length
*/
int get_gap(int i);

/*
Finds the size of array for storing gap sizes for shell algorithm
Input: size - size of array to be sorted
Output: int containing size of array for storing gaps
*/
int get_gaps_size(int size);

// Insertsort

/*
Sorts the subarray of the array depending on step
Input: arr - pointer to array, size - size of array, from - starting position
step - gap between elements in subarray (0 sorts all the array)
*/
void sort_insert(int * arr, int size, int from, int step);

// Quicksort

/*
Sorts the subarray using quick-sort method
Input: arr - pointer to array, start - starting position, end - ending position
*/
void sort_quick(int * arr, int start, int end);

/*
Finds pivot in subarray
Input: arr - pointer to array, start - starting position, end - ending position
Output: resulting pivot
*/
int find_pivot(int * arr, int start, int end);

// Heapsort

/*
Sorts the array using heap-sort method
Input: arr - pointer to array, size - array size
*/
void sort_heap(int * arr, int size);

/*
Builds a heap from given array
Input: arr - pointer to array, size - size of array
*/
void build_heap(int * arr, int size);