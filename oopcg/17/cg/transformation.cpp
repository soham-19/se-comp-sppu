#include<iostream>
#include<graphics.h>
using namespace std;

class polygon
{
public: void display()
	{
	int i,j,n=3;
	int a[3][3];
	setcolor(WHITE);
	line(320,0,320,480);
	line(0,240,640,240);
	cout<<"\nEnter vertices of Triangle";
	for(i=0;i<n;i++)
		{
		cout<<"Enter the x"<<i+1<<" coordinate: ";
		cin>>a[i][0];
		}
	for(i=0;i<n;i++)
		{
		cout<<"Enter the y"<<i+1<<" coordinate: ";
		cin>>a[i][1];
		}
		
	a[0][2]=a[1][2]=a[2][2]=1;
	setcolor(RED);
	line(a[0][0],a[0][1],a[1][0],a[1][1]);
	line(a[1][0],a[1][1],a[2][0],a[2][1]);
	line(a[0][0],a[0][1],a[2][0],a[2][1]);
	
	}
};

int main()
{
int gd,gm;
initgraph(&gd,&gm,NULL);

polygon p;
p.display();

delay(20000);
closegraph();
return 0;
}
