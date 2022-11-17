#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
class shape
{
	float x1,x2,y1,y2,icolor;
	float dx,dy,steps,xinc,yinc,x,y;
	public:
	void dda(float a,float b,float c, float d, float i)
	{
	

		int j;
		x1=a;
		y1=b;
		x2=c;
		y2=d;
		icolor=i;
		dx=x2-x1;
		dy=y2-y1;
		if(fabs(dx)>fabs(dy))
		steps=dx;
		else
		steps=dy;
		xinc=dx/steps;
		yinc=dy/steps;
		x=x1;
		y=y1;
		for(j=0;j<steps;j++)
		{
			putpixel(floor(x),floor(y),icolor);
			x+=xinc;
			y+=yinc;

		}
}
};
int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	shape triangle;
	shape rectangle;
	triangle.dda(100,200,250,100,10);
	triangle.dda(100,200,250,300,10);
	triangle.dda(250,100,400,200,10);
	triangle.dda(250,300,400,200,10);
	rectangle.dda(100,100,400,100,1);
	rectangle.dda(100,100,100,300,1);
	rectangle.dda(100,300,400,300,1);
	rectangle.dda(400,100,400,300,1);
	setcolor(RED);
	circle(250,200,82);
	
	delay(50000);
	closegraph();
	return(0);
}
		

