#include<iostream>
#include<graphics.h>

using namespace std;
	int main(){
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	line(0,240,640,240);
	line(320,0,320,480);
	int x1,x2,y1,y2,ln;
	cout<<"enter x1,x2,y1,y2 respectively";
	cin>>x1;
	cin>>y1;
	cin>>x2;
	cin>>y2;
	int dx=abs(x2-x1);
	int dy=abs(y2-y1);
	if ( dx>=dy){
		ln=dx;
	}
	else
	{ 
	ln=dy;
	}
	float dlx=dx/ln;
	float dly=dy/ln;
	int i=0;
	int x=x1,y=y1;
	while(i<=ln){
		putpixel(int(x),int(y),8);
		x=x+dlx;
		y=x+dly;
		i++;
		}
	delay(1000);
	closegraph();
	return 0;
}
	
	
