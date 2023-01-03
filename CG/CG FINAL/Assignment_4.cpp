#include<graphics.h>
#include<iostream>
#include<math.h>

class Tran
int main()
{
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(100,400,400,100);
	getch();
	closegraph();
}
