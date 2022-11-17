#include<iostream>
#include<graphics.h>
#include<stdio.h>
void dda(int x1,int y1,int x2,int y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int steps=dx>dy?dx:dy;
	float xInc=dx/(float)steps;
	float yInc=dy/(float)steps;
	float x=x1;
	float y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,14);
		x+=xInc;
		y+=yInc;
	}
}
void display(int xc,int yc,int x,int y)
{
	putpixel(xc+x, yc+y, 4);
	putpixel(xc-x, yc+y, 4);
	putpixel(xc+x, yc-y, 4);
	putpixel(xc-x, yc-y, 4);
	putpixel(xc+y, yc+x, 4);
	putpixel(xc-y, yc+x, 4);
	putpixel(xc+y, yc-x, 4);
	putpixel(xc-y, yc-x, 4);  //RED
}
void Circle(int x1,int y1,int r)
{
	int x=0,y=r;
	int d=3-2*r;
	display(x1,y1,x,y);
	while(y>=x)
	{
		x++;
		if(d>0)
		{
			y--;
			d=d+4*(x-y)+10;
		}
		else
			{
				d=d+4*x+6;
			}
	display(x1,y1,x,y);
	}
	//putpixel(50,50,RED);
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	putpixel(50,50,RED);

	Circle(150,180,57);
	Circle(150,180,57/2);
	dda(102,150,198,150);
	dda(102,150,150,236);
	dda(150,236,198,150);
	getch();
	closegraph();
	return 0;
}

	



