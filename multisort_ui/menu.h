#pragma once

// Different available selections
enum Choice { Bubble, Shell, Quick, Heap, Regenerate, Print, Error, Exit };

/*
Draws the basic menu
*/
void draw_menu();

/*
Gets the user choice
Output: selected choice (enum)
*/
Choice get_choice();

/*
Executes the choice
Input: choice - the action to use, arr - pointer to array, size - size of used array
*/
void make_action(Choice choice, int * arr, int size);