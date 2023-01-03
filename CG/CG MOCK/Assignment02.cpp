#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class dda
{
	public:		void drawline(float,float,float,float,int);
};

void dda::drawline(float x1, float y1, float x2, float y2, int col) 
{
	float x, y, dx, dy, len;
	int i;
	
	dx = x2-x1;			
	dy = y2-y1;
	
	if (dx >= dy)		
		len = dx;
	
	else 			
		len = dy;
	
	dx = (x2-x1)/len;
	dy = (y2-y1)/len;
	
	x = x1 + 0.5;		
	y = y1 + 0.5;
	
	i = 1;
	while(i<=len)
	{
		putpixel(x,y,col);
//		delay(2);
		x += dx;		
		y += dy;
		i++;
	}
}
int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	dda d1;
	//	brescircle b1;
	//		setcolor(YELLOW);
	d1.drawline(212.3,350,388.3,350,12);
	d1.drawline(212.3,350,300,200,12);
	d1.drawline(300,200,388.3,350,12);
//	setcolor(12);
//	b1.mycircle(300,300,50,12);
//	setcolor(YELLOW);
//	b1.mycircle(300,300,100,12);
	getch();
	closegraph();
	return 0;
}
