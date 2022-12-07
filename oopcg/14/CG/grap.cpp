#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	putpixel(100,100,RED);
	setcolor(WHITE);
	rectangle(0,0,100,100);
	line(0,50,50,0);
	line(50,0,100,50);
	line(100,50,50,100);
	line(50,100,0,50);
	circle(50,50,35);
	delay(10000);
	closegraph();
	return 0;
}

