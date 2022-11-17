#include<iostream>
#include<graphics.h>
#include <math.h>
using namespace std;

void DDA_line(float x1,float x2,float y1,float y2,float color)
{
    float x,y,x1,y1,x2,y2,dx,dy,z;

    int i; 
    dx=abs(x2-x1);
    dy=abs(y2-y1);
	if(abs(dx)>abs(dy))
	{
		steps=dx;
	}
	else
	{
		steps=dy;
	} 
	xinc=dx/steps;
	yinc=dy/steps;
 
	x=x1;
	y=y1;
	for(i=o;i<=steps;i++)
	{
		putpixel(floor(x),floor(y));
		x=x+xinc;
		y=y+yinc;
	}

	display(10000);
	closegraph();
}




