#include <iostream>
#include "menu.h"
#include "arrays.h"

using namespace std;

/*
Fills the array of user-chosen length.
Lets the user sort it using different methods.
(Bubblesort, Shellsort)
*/

void main()
{

	Choice choice;
	int size;

	// Create basic array to use and fill with random nums
	printf_s("Choose the size of array: ");
	scanf_s("%d", &size);
	int * arr = new int[size];
	fill_random(arr, size);

	// Repeat the cycle until user decides to end the program
	do
	{
		system("CLS");
		make_action(Print, arr, size);
		draw_menu();
		choice = get_choice();
		make_action(choice, arr, size);
	}
	while (choice != Exit);
}