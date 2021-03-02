#include <stdio.h>
#include <stdlib.h>
#include <termios.h> //For more info: pubs.openfroup.org/onlinepubs/7908799/xsh/termios.h.html
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>

//console: 36 l; 100 c

//Constants

#define UP_ARROW (char) 'w'
#define LEFT_ARROW (char) 'a'
#define RIGHT_ARROW (char) 'd'
#define DOWN_ARROW (char) 's'

#define ENTER_KEY 10

#define SNAKE_HEAD (char) 'H'
#define SNAKE_BODY (char) 'B'
#define FOOD (char) 'X'
#define BLANK (char) ' '

#define SNAKE_MAX_LENGTH (int) 500

// Protoypes

void  clrscr();
void  collisionDetector();
int*  directionalInput(int dir[]);
void  drawCanvas(int x, int y);
char  getKeyWhenPressed();
int   kbHit();
void  moveCursor(int x, int y);
int*  pickFoodLocation(int x, int y);
void  startSnakeGame();
int*  updateHeadPosition(int x, int y);

// Functions

int main()
{
	clrscr();
	startSnakeGame();
//	char c = NULL;
//	while (&c!=NULL)
//	{	
//		c=getKeyWhenPressed();
//	}
//	printf("You pressed %c !", c);
	clrscr();
	return 0;
}

// clrscr();
//
// Parameters: none
// Return: void
void clrscr()
{
	system("clear");
}

// collisionDetector()
//
// Parameters:
// Return:
void collisionDetector()
{

}

// directionalInput()
// Translates the user command in numerical friendly value.
// Parameters: void
// Return: int[2] -> int[0] stores the x coordinate
//		  -> int[1] stores the y coordinate
int* directionalInput(int direction[])
{
	int* pointer;
	direction[0] = 0;
	direction[1] = 0;
	char c = getKeyWhenPressed();
	switch (c)
	{
		case UP_ARROW : { direction[0] = -1; direction[1] = 0;} break;
		case DOWN_ARROW : { direction[0] = 1; direction[1] = 0; } break;
		case RIGHT_ARROW : { direction[0] = 0; direction[1] = 1; } break;
		case LEFT_ARROW : { direction[0] = 0; direction[1] = -1; } break;
		default: { direction[0] = 0; direction[1] = 0; }
	}
	pointer=direction;
	return pointer;
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

// getKeyWhenPressed()
// Test if a key on the keyboard was pressed.
// Parameters: none
// Return: char, the ascii code of the key pressed
char getKeyWhenPressed()
{
	char c=NULL;
	if (kbHit())
	{
		c=getchar();
	}
	return c;
}

// kbHit()
// Verifies if a key was pressed upon calling.
// Code from : https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
// Paraneters: none
// Return:int 1 -> if was pressed a key on keyboard
//		0 -> if not
int kbHit()
{
	struct termios oldt;
	struct termios newt;
	int ch;
	int oldflag;
	int r;

	tcgetattr(STDIN_FILENO, &oldt); 
	/*
		int tcgetattr(int fildes, struct termios *termios_pointer)	
		Usage: Get the parameters associated with the terminal refferred to by fildes and store them in the termios structure refferenced by termios_pointer
		Parameters: fildes -> open file descriptor asociated with the terminal
			    termios_pointer -> a pointer to a termios struct
		OBS: STDIN_FILENO is a file descriptor and determines the default way of io communication - the console. It is a macro defined in /usr/include/unistd.h
		For more info: pubs.opengroup.org/oninepubs/007904975/functions/tcgetattr.html
	*/
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	/*
		int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p)
		Usage: In this mode, set the parameters associated with the terminal refferred to by fildes and store them in the termios structure refferenced by termios_p. Because optional_actions is set to TCSANOW, the change shall occur immidiately.
		More info: pubs.opengroup.org/oninepubs/007904975/functions/tcsetattr.html
	*/

	oldflag = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldflag | O_NONBLOCK);
	/*
		int fcntl(int filedes, int cmd, ... )
		Usage: Set a file status flags, defined in <fcntl.h>
		More info: pubs.opengroup.org/onlinepubs/009604599/functions/fcntl.html
		Example: can be used for locking and unlocking a file
	*/

	ch = getchar();
	/*
		int getchar(void)
		Usage: Reads a single character from the standard imput stream stdin, and returns itas a code.
		More info: cplusplus.com/reference/cstdio/getchar/

	*/

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldflag);

	if (ch !=EOF)
	{
		ungetc(ch, stdin);
		/*
			int ungetc(int char, FILE *stream)
			Usage: inserts int char in the stream FILE *stream.
			More info: tutorialspoint.com/c_standard_library/c_function_ungetc.htm
		*/
		r=1;
	}
	else r=0;
	return r;
}

// moveCursor(int x, int y);
// Move the console cursor to a specific destination. Uses ESC character : 0x1b.
// To be used in a console with text writing mode enabled.
// Parameters: int x -> number of lines
//		int y -> number of collumns
// Return: void
void moveCursor(int x, int y)
{
	printf("%c[%d;%df",0x1b,x,y);
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


// startSnakeGame()
// The most important function after main().
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

	int* nextDirection=NULL;
	int x = 10;
	int y = 10;	
//	int i=0;
	int direction[] = { 0,0};
	drawCanvas(36,100); // enables a console of that size
	while (1)	
	{	if ((x==-1)||(y==-1))
		break;
		else
		{
			moveCursor(x,y);
			printf("%c" , SNAKE_HEAD);
			nextDirection=directionalInput(direction); //return the direction coordinates for next move
			x=x + *nextDirection;
			y=y + *(nextDirection+1);
		}
	}
} 


// updateHeadPosition(int x, int y);
//
// Parameters: int x ->
//		int y ->
// Return: int[], an array of 2 with the updated coordinates (x,y)
int* updateHeadPosition(int x, int y);
