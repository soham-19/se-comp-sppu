#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
class patern{
	public:
void dda(float n1,float m1,float n2,float m2)
{	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);	
	float m,xi,yi;
	float dx,dy,x,l,y;
	dx=fabs(n2-n1);
	dy=fabs(m2-m1);
	x=n1;
	y=m1;
	if (dx>dy)
	{
		l=dx;
			//p=p + 4*(x - y) + 10;
	}
	else
	{
		l=dy;
	}
	
	int i;
	xi=dx/l;
	yi=dy/l;
	for (i=0;i<l;i++)
	{
		putpixel(floor(x),floor(y),RED);
		x=x+xi;
		y=y+yi;
	}
	//delay(10000);
	//closegraph();
}
void bcd(int x,int y,int r)
{	int gd,gm;
	gd=DETECT;
	initgraph(&gm,&gd,NULL);
	int xi,yi,deli,limit,s,s2;
	xi=0;
	yi=r;
	deli=2*(1-r);
	limit=0;
	while (yi>=limit)
	{
	putpixel(x+xi,y+yi,RED);
	putpixel(x+xi,y-yi,RED);
	putpixel(x-xi,y-yi,RED);
	putpixel(x-xi,y+yi,RED);
	delay(10);
		if(deli<0)
		{s=(2*deli)-(2*yi)-1;
			if (s<=0)
			{xi=xi+1;
			yi=yi;
			deli=deli+(2*xi)+1;
			}
			else
			{xi=xi+1;
			yi=yi-1;
			deli=deli+(2*xi)-(2*yi)+2;
			}
		}
		else if(deli>0)
		{s2=(2*deli)+(2*xi)-1;
			if (s2<=0)
			{xi=xi+1;
			yi=yi-1;
			deli=deli+(2*xi)-(2*yi)+2;
			}
			else
			{
			yi=yi-1;
			deli=deli-(2*yi)+1;
			}
		}
		else if (deli==0)
		{xi=xi+1;
		yi=yi-1;
		deli=deli+(2*xi)-(2*yi)+2;
		}
	}
}
};
int main()
{	int m,xi,yi;
	int n1,m1,n2,m2,n3,m3;
	patern s1;
	//cout<<"enter a x1 and y1:";
	//cin>>n1>>m1;
	//cout<<"enter a x2 and y2:";
	//cin>>n2>>m2;
	//cout<<"enter a x3 and y3:";
	//cin>>n3>>m3;
	s1.dda(160,360,480,360);
	//s1.dda(160,360,320,120);
	//s1.dda(320,120,160,360);
	s1.bcd(320,240,100);
	delay(10000);
	closegraph();
	
return 0;
				
}

