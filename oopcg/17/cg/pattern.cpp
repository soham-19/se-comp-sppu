#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;

class dda	//class   
{
public:
	float x,y,dx,dy,ln,x11,y11;
	void dda_line(int x1,int y1,int x2, int y2);
};

void dda::dda_line(int x1,int y1,int x2, int y2)
{
	x11= (x2-x1);
	y11= (y2-y1);
	if (abs(x11)>=abs(y11))
		{	ln=abs(x11);
		}
	else{
		ln=abs(y11);
		}
	
	dx=x11/ln;
	dy=y11/ln;
	
	int i;
	float x=x1,y=y1;
	for(i=0;i<=ln;i++)
		{
			putpixel(float(x),float(y),RED);
			
			x=x+dx;
			y=y+dy;
			
		}
};
   
class c
{
int i;
float A,B,R,limit,ai,bi,di,df,d;
public:
	void circle(int A,int B, int R)
	{
	//A=;
	//B=;
	//R=;
	ai=0;
	bi=R;
	limit=0;
	di=2*(1-R);
	
	while(bi>=limit){
	putpixel(A+ai,B+bi,RED);
	putpixel(A+ai,B-bi,RED);
	putpixel(A-ai,B+bi,RED);
	putpixel(A-ai,B-bi,RED);
	if (di<=0)
	{
	d=2*di+2*bi-1;
	if(d<=0)
	{
	ai=ai+1;
	di=di+2*ai+1;
	}
	else
	{
	ai=ai+1;
	bi=bi-1;
	di=di+2*ai-2*bi+2;
	}
	}
	else if (di>0)
	{
	df=2*di+ai-1;
	if (df<=0)
	{
	ai=ai+1;
	bi=bi-1;
	di=di+2*ai-2*bi+2;
	}
	else
	{
	bi=bi-1;
	di=di-2*bi+1;
	}
	}
	}
	}
	};
	
	
int main()  // main function
	{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	dda l;
	l.dda_line(320,140,235,290);
	l.dda_line(320,140,405,290);
	l.dda_line(235,290,405,290);
	
	c cir1,cir2;
	cir1.circle(320,240,50);
	cir2.circle(320,240,100);
	
	
		delay(10000);
		closegraph();
		return 0 ;
	}

