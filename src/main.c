#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>

//console: 36 l; 100 c

//Constants

#define UP_ARROW (char) 'W'
#define LEFT_ARROW (char) 'A'
#define RIGHT_ARROW (char) 'D'
#define DOWN_ARROW (char) 'S'

#define ENTER_KEY 10

#define SNAKE_HEAD (char) 'H'
#define SNAKE_BODY (char) 'B'
#define FOOD (char) 'X'
#define BLANK (char) ' '

#define SNAKE_MAX_LENGTH (int) 5

void  moveCursor(int x, int y);
void  drawCanvas(int x, int y);
char  kbPressed();
int* pickFoodLocation(int x, int y);
int* updateHeadPosition(int x, int y);
void startSnakeGame();
void clrscr();
void print(int x, int y);
int kbHit();
int kbHit2();

int main()
{
	system("clear");
	startSnakeGame();
	return 0;
}

// startSnakeGame()
//
// Parameters:
// Return:
void startSnakeGame()
{
	int length = 3; // initial snake length

	int historyX[SNAKE_MAX_LENGTH]; // for saving the x coordinates of the snake body
	int historyY[SNAKE_MAX_LENGTH]; // for saving the y coordinates of the snake body
		
	int canvasH = 36;
	int canvasW = 100;
	drawCanvas(canvasW,canvasH); // after this call the gameSpace will be canvasH-2, canvasW-2

	int position[] = {0,0};
	int* pPosition;
	pPosition=&position[0];
	
	moveCursor(15,15);
	printf("%c", FOOD);
	int i=0;
	for (i=0;i<5;i++)
	{
		char c = kbPressed();
		switch (c)
		{	
			case UP_ARROW: print(16,15); break;
			case DOWN_ARROW: print(14,15); break;
			case LEFT_ARROW: print(15,14); break;
			case RIGHT_ARROW: print(15,16); break;
		}
	}

	drawCanvas(36,100); // enables a console of that size
	 
} 

// drawCanvas(int x, int y);
// Draw a border on the limit of the canvas.
// Parameters: int x -> width of the canvas
// 		int y-> height of the canvas
// Return: void
void drawCanvas(int x, int y)
{
	// to be filled
}



void print(int x, int y)
{
	moveCursor(x,y);
	printf("%c",FOOD);
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

// kbHit()
// Verifies if a key was pressed upon calling.
// Code from : https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
// Paraneters: none
// Return:int 1 -> if was pressed a key on keyboard
//		0 -> if not
int kbHit()
{
	struct termios oldt, newt;
	int ch;
	int oldf;
	int r;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch !=EOF)
	{
		ungetc(ch, stdin);
		r=1;
	}
	else r=0;
	return r;
	

}

// kbHit2()
int kbHit2()
{
	struct timeval tv;
	fd_set rdfs;

	tv.tv_sec=0;
	tv.tv_usec=0;

	FD_ZERO(&rdfs);
	FD_SET (STDIN_FILENO, &rdfs);

	select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &rdfs);
}


// kbPressed()
// Sense if a key on the keyboard was pressed
// Parameters: none
// Return: char, the ascii code of the key pressed
char kbPressed()
{
	char c=NULL;
	scanf("%c",c); // maybe it won't work because scanf block the thread of execution
		       // until it's pressed a key and is not listening in the event of a pressed ke
	return c;
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
