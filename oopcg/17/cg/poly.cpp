#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);

int i,n;
cout<<"\nEnter no. of vertices of polygon: ";
cin>>n;
int x[n],y[n];
	for(i=0;i<n;i++)
		{
		setcolor(RED);
		cout<<"Enter the x"<<i+1<<" coordinate: ";
		cin>>x[i];
		cout<<"Enter the y"<<i+1<<" coordinate: ";
		cin>>y[i];
		}
	for(i=0;i<n-1;i++)
		{
		
		line(x[i],y[i],x[i+1],y[i+1]);
		}
		
		
	
	
	line(x[n-1],y[n-1],x[0],y[0]);
	
		


delay(10000);
closegraph();
return 0;
}
