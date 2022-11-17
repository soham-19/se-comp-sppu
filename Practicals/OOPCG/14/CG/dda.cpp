#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;
	
class algoint{
		 
	float x1,x2,y1,y2,step;
	
	public:
	algoint()
		{   
		cout<<"enter x1,x2,y1,y2 respectively";
		cin>>x1;
		cin>>y1;
		cin>>x2;
		cin>>y2;
}
	
	void fun1(){	
		 int Dx=x2-x1;
		int Dy=y2-y1;
		if ( abs(Dx)>=abs(Dy)){
			step=Dx;
		}
		else
		{ step=Dy;
		}
		float dx=Dx/step,dy=Dy/step;
		int i=0;
		float x=x1,y=y1;
		putpixel(floor(x),floor(y),3);
		while(i<=step){
			putpixel(floor(x),floor(y),3);
			x=x+dx;
			y=x+dy;
			i++;
		}
	}
	
};
int main(){
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	algoint l1;
	l1.fun1();
	//algoint l2;
	//l2.fun1();
	//algoint l3;
	//l3.fun1();
	
	line(0,240,640,240);
	line(100,0,100,420);
	delay(2500);
	closegraph();
	return 0;	

}



















	
