#include<iostream>
#include<graphics.h>
using namespace std;

class circles
{
	
	public:
	int x1,y1,xc,yc,R,di,d,d1;
	void get();
	void put();
	void cir();
};
void circles::get()

{
	cout<<"enter coordinate x and y that is center:";
	cin>>xc>>yc;
	cout<<"enter radius of circle";
	cin>>R;
}
void circles::put()
{
	cout<<"center point is:"<<xc<<yc;
	cout<<"radius is"<<R;
}
void circles::cir()
{
	x1=0;
	y1=R;
	di=2*(1-R);
	int limit=0;
	while(y1>=limit)
	{
		putpixel(xc+x1, yc+y1, 3);
		putpixel(xc-x1, yc+y1, 3);
		putpixel(xc-x1, yc-y1, 3);
		putpixel(xc+x1, yc-y1, 3);
		
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
	circles obj;
	obj.get();
	obj.put();
	obj.cir();
	delay(100000);
	return 0;
}
