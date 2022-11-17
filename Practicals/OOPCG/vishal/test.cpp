#include<iostream>
#include<graphics.h>
using namespace std;

class draw
{
	public:
		void drawline(int x1,int y1,int x2,int y2)
		{
			line(x1,y1,x2,y2);
		}
};

class poly:public draw
{
	int x[10],y[10],n;
	public:
		void getdata()
		{
			int i;
			int gd=DETECT,gm;
			cout<<"Enter the no of vertices of polygon";
			cin>>n;
			for(i=0;i<n;i++)
			{
				cout<<"\nEnter the coordinates of polygon\n";
				cin>>x[i];
				cin>>y[i];
			}
			
			initgraph(&gd,&gm,NULL);
			for(i=0;i<n;i++)
			{
				if(i==n-1)
				{
					drawline(x[0],x[0],x[i],y[i]);
				}
				else
				{
					drawline(x[i],x[i],x[i+1],y[i+1]);
				}
			}
		}
};


int main()
{
	poly p;
	p.getdata();
	getch();
	closegraph();
	return 0;
}
