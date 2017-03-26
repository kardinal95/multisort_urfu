#include <iostream>
#include "menu.h"
#include "arrays.h"
#include "arrays_sort.h"

/*
Draws the basic menu
*/
void draw_menu()
{
	printf_s("Available options:\n");
	printf_s("1 - Fill array with random numbers,\n");
	printf_s("2 - Sort the array (bubble),\n");
	printf_s("3 - Sort the array (shell),\n");
	printf_s("4 - Sort the array (quick),\n");
	printf_s("5 - Sort the array (heap),\n");
	printf_s("0 - Exit program.\n");
}

/*
Gets the user choice
Output: selected choice (enum)
*/
Choice get_choice()
{
	Choice choice;
	int selected;

	printf_s("Choose an option: ");
	scanf_s("%d", &selected);

	switch (selected)
	{
	case 1:
		choice = Regenerate;
		break;
	case 2:
		choice = Bubble;
		break;
	case 3:
		choice = Shell;
		break;
	case 4:
		choice = Quick;
		break;
	case 5:
		choice = Heap;
		break;
	case 0:
		choice = Exit;
		break;
	default:
		choice = Error;
		break;
	}

	return choice;
}

/*
Executes the choice
Input: choice - the action to use, arr - pointer to array, size - size of used array
*/
void make_action(Choice choice, int * arr, int size)
{
	switch (choice)
	{
	case Bubble:
		// Sort the array using bubble sort method
		sort_bubble(arr, size);
		break;
	case Shell:
		// Sort the array using shell sort method
		sort_shell(arr, size);
		break;
	case Quick:
		// Sort the array using quick sort method
		sort_quick(arr, 0, size-1);
		break;
	case Heap:
		// Sort the array using quick sort method
		sort_heap(arr, size);
		break;
	case Regenerate:
		// Fill array with random numbers
		fill_random(arr, size);
		break;
	case Print:
		// Print the contents of array
		print_array(arr, size);
		break;
	case Error:
		// Show the error message
		// Flush to avoid infinite cycles
		_flushall();
		printf_s("Wrong command specified!\n");
		system("PAUSE");
		break;
	}
}