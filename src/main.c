#include <stdio.h>
#include <stdlib.h>

void moveCursor(int x, int  y);

int main()
{
	system("clear");
	moveCursor(15,5);
	printf("Hello world!\n");
	return 0;
}

void moveCursor(int x, int y)
{
	printf("%c[%d;%df",0x1b,x,y);
}
