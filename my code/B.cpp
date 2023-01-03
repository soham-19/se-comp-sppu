#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;
class ball{
	public:
	void sine()
		{
			setcolor(CYAN);
			line(getmaxx()/2,0,getmaxx()/2,getmaxy());
			line(0,getmaxy()/2,getmaxx(),getmaxy()/2);	
			
		}
	void sine(int angle)
	{
			double x,y;
			//Generate sine wave
		for(x=0;x<getmaxx();x+=1)
		{
		
	
			//Calculate y for corresponding x
			y=200*sin(angle*3.14/180);		//200=height
											//at 0=y=0
			y=getmaxy()/2-y;
		
			setcolor(8);
			fillellipse(x,y,25,25);
			delay(40);
	
	
			cleardevice();
			
			angle+=1;
			sine();
			
	}
}
		
};
int main()
{
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	int angle;
	
	cout<<"ENTER THE ANGLE:";
	cin>>angle;
	ball obj;
	
	obj.sine(angle);
	//obj.sine();
	delay(5000);
	getch();
	closegraph();
	return 0;
}
