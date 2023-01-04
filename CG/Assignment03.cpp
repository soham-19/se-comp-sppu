#include <iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

class DDA
{
	public : 	void drawline(float,float,float,float,int);
};

void DDA::drawline(float x1, float y1, float x2, float y2, int col) 
{
	float x, y, dx,dy, len;
	int i=1;
	
	dx = x2-x1;
	dy = y2 - y1;
	
	if(abs(dx) >= abs(dy))
		len = abs(dx);
	else
		len = abs(dy);
		
	dx /= len;
	dy /= len;
	x = x1 + 0.5;
	y = y1 + 0.5;
	while(i<=len)
	{
		putpixel(x,y,col);
		delay(1);
		x += dx;
		y += dy;
		i++;
	}
}
class brecircle
{	
	float xi, yi, limit, d, di;
	
	public:
		void mv();
		void mh();
		void md();
		void mycircle(int xc, int yc, int r, int col);
};	

void brecircle::mycircle(int xc, int yc, int r, int col) 
{
	limit = 0;
	xi = 0;
	yi = r;
	di = 2*(1-r);
	while (yi > limit)
	{
		putpixel(xc+xi, yc+yi, col);	//delay(1);
		putpixel(xc+xi, yc-yi, col);//	delay(1);
		putpixel(xc-xi, yc-yi, col);//	delay(1);
		putpixel(xc-xi, yc+yi, col);	delay(1);
		
		if(di <0)		{
			
			d = 2*(di+yi) -1;
			if(d<0)
				mh();
			else	md();
			
		}
		
		else if(di >0)
		{
			d = 2*(di-xi) - 1;
			
			if(d <0)
				md();
			else
				mv();
		}
		else
		md();
	}
}
void brecircle::mh()
{
	xi++;
	di+=2*xi+1;
}
void brecircle::md()
{
	xi++;
	yi--;
	di+=2*(xi-yi+1);
}
void brecircle::mv()
{
	yi--;
	di-=2*yi+1;
}
int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	DDA d1;
	brecircle b1;
	d1.drawline(388.3,350,212.3,350,12);
	d1.drawline(212.3,350,300,200,12);
	d1.drawline(300,200,388.3,350,12);
	b1.mycircle(300,300,50,YELLOW);
	b1.mycircle(300,300,100,CYAN);
	getch();
	closegraph();
	return 0;
}
