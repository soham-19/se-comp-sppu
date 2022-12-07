#include<iostream>
#include<graphics.h>
using namespace std;
class Bresenham
{
	public:
		int x,xi,y,yi,r,D,sig1,sig2,limit;
		void c(int,int,int);
		void mh();
		void md();
		void mv();
};

void Bresenham::c(int x, int y, int r)
{
	cin>>x;
	cin>>y;
	cin>>r;	

	limit=0;
	xi=0;
	yi=r;
	D=2*(1-r);

	while (yi>=limit)
	{
		putpixel(x+xi,y+yi,RED);
		putpixel(x+xi,y-yi,RED);
		putpixel(x-xi,y+yi,RED);
		putpixel(x-xi,y-yi,RED);
	}

	if (D<0)
	{
		sig1>((2*D)+(2*yi)-1);


		if (sig1<=0)
		{
			mh();
		}

		else
		{
			md();
		}
	circle(x,y,r);
	}
	else if (D>0)
	{
		sig2 = ((2*D)-(2*xi)-1);

		if (sig2<=0)
		{
			md();
		}

		else
		{
			mv();
		}
	circle(x,y,r);
	}
		
	else if (D=0)
	{
		md();
	}
	circle(x,y,r);
}

void Bresenham::mh()
{
	xi=xi+1;
	D=(D+(2*xi)+1);
}

void Bresenham::mv()
{
	xi=xi+1;
	D=(D-(2*yi)+1);
}

void Bresenham::md()
{
	x=xi+1;
	y=yi+1;
	D=(D+(2*xi)-(2*yi)+2);
}

int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	Bresenham t;
	t.c();
	delay(20000);
	closegraph();
	return 0;
}
 
