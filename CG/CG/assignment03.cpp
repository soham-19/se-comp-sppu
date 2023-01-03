#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class ddaline{
	float x1,y1,x2,y2;
	
	public:
		void drawline(float x1,float y1,float x2,float y2);
};
void ddaline::drawline(float x1,float y1,float x2,float y2)
{
	float x,y,dx,dy,len;
	int i;
	dx=x2-x1;
	dy=y2-y1;
	
	if(dx>=dy)
	len=dx;
	
	else
	len=dy;
	
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	
	x=x1+0.5;
	y=y1+0.5;
	
	i=1;
	while(i<=len)
	{
		putpixel(x,y,RED);
		x=x+dx;
		y=y+dy;
		i=i+1;
	}	
}

class brescircle{
	float xc,yc,xi,yi,limit,d,d_,r,di;
	
	public:
		void mycircle(int xc,int yc,int r);
		void mh();
		void md();
		void mv();
};
void brescircle::mycircle(int xc,int yc,int r)
{
	limit=0;
	xi=0;
	yi=r;
	di=2*(1-r);
	
	while(yi>=limit)
	{
		putpixel(xc+xi,yc+yi,RED);
		putpixel(xc+xi,yc-yi,RED);
		putpixel(xc-xi,yc-yi,RED);
		putpixel(xc-xi,yc+yi,RED);
		
		
		
		if(di<0)
		{
			d=2*di+2*yi-1;
			
			if(d<=0)
			mh();
			
			else
			md();
		}
		
		else if(di>0)
		{
			d_=2*di-2*xi-1;
			
			if(d_<=0)
			md();
			
			else
			mv();
		}
		else if(di==0)
		md();
	}
}

void brescircle::mh()
{
	xi=xi+1;
	di=di+2*xi+1;
}
void brescircle::md()
{
	xi=xi+1;
	yi=yi-1;
	di=di+2*xi-2*yi+2;
}
void brescircle::mv()
{
	yi=yi-1;
	di=di-2*yi+1;
}


int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	ddaline d1;
	brescircle b1;
	
	d1.drawline(212.3,350,388.3,350);
	d1.drawline(212.3,350,300,200);
	d1.drawline(300,200,388.3,350);
	b1.mycircle(300,300,50);
	b1.mycircle(300,300,100);
	getch();
	closegraph();
	return 0;
}
