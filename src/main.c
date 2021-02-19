#include <stdio.h>
#include <stdlib.h>

//console: 36 l; 100 c

void  moveCursor(int x, int y);
void  drawCanvas(int x, int y);
char  kbPressed();
int* pickFoodLocation(int x, int y);
int* updateHeadPosition(int x, int y);
void snake();
void clrscr();

int main()
{
	system("clear");
	snake();
	return 0;
}

// snake()
//
// Parameters:
// Return:
void snake()
{
	int sLength[100];
	int x;
	int y;
	int position[] = {0,0};
	int* pPosition;
	pPosition=&position[0];

	drawCanvas(36,100); // enables a console of that size
	 
} 

// clrscr();
//
// Parameters: none
// Return: void
void clrscr()
{
	system("clear");
}

// updateHeadPosition(int x, int y);
//
// Parameters: int x ->
//		int y ->
// Return: int[], an array of 2 with the updated coordinates (x,y)
int* updateHeadPosition(int x, int y)
{
	int* p=NULL;
	return p;
}

// pickFoodLocation(int x, int y);
//
// Parameters : int x -> number of lines of the canvas
//		int y -> number of collumns of the canvas
// Return: int[], an array of 2 with the coordinates of the food item
int* pickFoodLocation(int x, int y)
{
	int* p=NULL;
	return p;
}

// kbPressed()
// Sense if a key on the keyboard was pressed
// Parameters: none
// Return: char, the ascii code of the key pressed
char kbPressed()
{
	char c=NULL;
	return c;
}

// drawCanvas(int x, int y);
//
//
//
//
void drawCanvas(int x, int y)
{
	
}

// moveCursor(int x, int y);
// Move the console cursor to a specific destination. Uses ESC character : 0x1b.
// To be used in t console with text writing mode enabled.
// Parameters: int x -> number of lines
//		int y -> number of collumns
// Return: void
void moveCursor(int x, int y)
{
	printf("%c[%d;%df",0x1b,x,y);
}
