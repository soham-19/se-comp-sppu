#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class algo
{
	private:
	int x11;int y11;int x22;int y22;int icolour;
	public:
	
	int x1,y1,xc,yc,R,di,d,d1;
	void get();
	void put();
	void cir();
 
	void  DDA_line(int x11,int y11,int x22,int y22,int icolour)
		{
		int i;
		float dx,dy,steps,xinc,yinc,X,Y;
		dx=(x22-x11);
		dy=(y22-y11);
		if (fabs(dx)>fabs(dy))
		{
		steps=fabs(dx);
		}
		else
		{
		steps=fabs(dy);
		}
		xinc=dx/steps;
		yinc=dy/steps;
		X=x11;
		Y=y11;
		for (i=0;i<steps;i++)
		{
		putpixel(floor(X),floor(Y),icolour);
		X=X+xinc;
		Y=Y+yinc;
		}
		}
};

void algo::get()

{
	cout<<"enter coordinate x and y that is center:";
	cin>>xc>>yc;
	cout<<"enter radius of circle";
	cin>>R;
}
void algo::put()
{
	cout<<"center point is:"<<xc<<yc;
	cout<<"radius is"<<R;
}
void algo::cir()
{
	x1=0;
	y1=R;
	di=2*(1-R);
	int limit=0;
	while(y1>=limit)
{
	putpixel(xc+x1, yc+y1, 3);
	putpixel(xc-x1, yc+y1, 4);
	putpixel(xc-x1, yc-y1, 5);
	putpixel(xc+x1, yc-y1, 6);

	
	
	if(di<=0)
		{
				d=(2*di)-(2*y1)-1;
				if(d<=0)
					{
					
						x1=x1+1;
						di=di+(2*x1)+1;
					}
				else
				{
						
					x1=x1+1;
					y1=y1-1;
					di=di+(2*x1)-(2*y1)+2;
				}
		}
	else if(di>0)
	{
		d=(2*di)-(2*x1)-1;
		if(d<=0)
		{
					x1=x1+1;
					y1=y1-1;
					di=di+(2*x1)-(2*y1)+2;
		}
		else
		{
		y1=y1-1;
		di=di-(2*y1)+1;
		}
	}
		
	
}
}


int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
algo obj;

obj.DDA_line(120,120,240,120,RED);


obj.DDA_line(240,120,240,240,RED);
obj.DDA_line(240,240,120,240,RED);

obj.DDA_line(120,240,120,120,RED);

obj.DDA_line(120,180,180,120,YELLOW);
obj.DDA_line(180,120,240,180,YELLOW);

obj.DDA_line(240,180,180,240,YELLOW);

obj.DDA_line(120,180,180,120,YELLOW);

obj.DDA_line(120,180,180,240,YELLOW);

	obj.get();
	obj.put();
	obj.cir();					//180,180,40



delay(500000);
return 0;
closegraph();

}

