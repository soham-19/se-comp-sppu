#include<iostream>
#include<graphics.h>
using namespace std;
class cg
{
private:
	int i;
	float dx,dy,steps,x,y,xi,yi;
public:
	void drawline(float,float,float,float,char);
	
};

void cg::drawline(float x1,float y1,float x2,float y2,char color)
{
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(fabs(dx)>fabs(dy))
	{
		steps=fabs(dx);
	}
	else
	{
		steps=fabs(dy);
	}
	xi=dx/steps;
	yi=dy/steps;
	x=x1;
	y=y1;
	for(i=0;i<steps;i++)
	{
		putpixel(floor(x),floor(y),color);
		x=x+xi;
		y=y+yi;
	}
}
int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);
cg c1;

c1.drawline(320,200,420,400,RED);
c1.drawline(320,200,220,400,RED);
c1.drawline(220,400,420,400,RED);
delay(100000);
closegraph();
return 0;
}




