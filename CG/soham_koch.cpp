//// soham kulkarni
//#include<iostream>
//#include<graphics.h>
//#include<math.h>
//using namespace std;
//
//class KochCurve{
//
//    public:
//
//        void draw(int, int, int, int, int, int);
//};
//
//void KochCurve::draw(int x1, int y1, int x2, int y2, int itr, int color) {
//	
//	int x3, y3, x4, y4, x, y;
//    setcolor(color);
//    
//    float angle = 60*M_PI/180;
//    
//    if(itr == 0)
//    	line(x1,y1,x2,y2);
//    	
//    else {
//    	delay(10);
//    	
//    	x3 = ((2*x1) + x2)/3;
//    	 y3 = ((2*y1) + y2)/3;
//    	
//    	 x4 = (x1 + (2*x2))/3;
//    	 y4 = (y1 + (2*y2))/3;
//    	
//    	 x = x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
//    	
//    	 y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);
//    	
//    	draw(x1,y1,x3,y3,itr-1,color);
//    	draw(x3,y3,x,y,itr-1,color);
//    	draw(x,y,x4,y4,itr-1,color);
//    	draw(x4,y4,x2,y2,itr-1,color);
//	}
//}
////			triangle (200,266), (100,100), (300,100)
//int main(){
//	
//	int itr;
//	
//	cout << "Enter number of iterartions : ";
//	cin >> itr;
//	
//	KochCurve k;
//	
//	int gd = DETECT, gm;
//	
//	initgraph(&gd,&gm,NULL);
//	
//	k.draw(200,266,100,100,itr,YELLOW);
//	k.draw(100,100,300,100,itr,GREEN);
//	k.draw(300,100,200,266,itr,RED);
//	
//	delay(100000);
//	
//	closegraph();
//	
//	return 0;
//}

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class kochcurve{
	public:
		void koch(int x1,int y1,int x2,int y2, int itr){
			int x,y,x3,y3,x4,y4;
			int dx,dy;
			
			float angle=60*(3.14/180);
			
			if(itr==0)
			{
				line(x1,y1,x2,y2);
			}
			else
			{
				delay(10);
				x3=((2*x1)+x2)/3;
				y3=((2*y1)+y2)/3;
				x4=(x1+(2*x2))/3;
				y4=(y1+(2*y2))/3;
				
				x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
				y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);
				
				koch(x1,y1,x3,y3,itr-1);
				koch(x3,y3,x,y,itr-1);
				koch(x,y,x4,y4,itr-1);
				koch(x4,y4,x2,y2,itr-1);
			}
		}
};

int main()
{
	kochcurve k;
	
	int it;
	
	cout<<"Enter number of iterations";
	cin>>it;
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	k.koch(200,266,100,100,it);
	k.koch(100,100,300,100,it);
	k.koch(300,100,200,266,it);
	
	getch();
	
	delay(1000);
	
	closegraph();
	return 0;
	
	
}
