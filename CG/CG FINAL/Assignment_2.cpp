#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class Koch
{
	float angle;
	public:
		Koch(){
			angle = 60*M_PI/180;
		}
		
		void draw(int,int,int,int,int);
};

void Koch::draw(int x1, int y1, int x2, int y2,int it) 
{
	if (it==0)
		line(x1,y1,x2,y2);
	else
	{
		int x3, y3, x4, y4, x, y;
		
		x3 = (2*x1+x2)/3;
		y3 = (2*y1+y2)/3;
		x4 = (x1+2*x2)/3;
		y4 = (y1+2*y2)/3;
		
		x = x3 + (x4-x3)*cos(angle) + (y4-y3)*sin(angle);
		
		y = y3 - (x4-x3)*sin(angle) + (y4-y3)*cos(angle);
		
		draw(x1,y1,x3,y3,it-1);
		draw(x3,y3,x,y,it-1);
		draw(x,y,x4,y4,it-1);
		draw(x4,y4,x2,y2,it-1);
		
		delay(10);
	}
}

int main()
{
	cout << "ITERATIONS : ";
	int it = 0,itr;
	cin >> itr;
	
	int gd = DETECT, gm;
	
	initgraph(&gd,&gm,NULL);
		Koch k;
		
		while(it<=itr)
		{
	setcolor(12);
	k.draw(200,266,100,100,it);				setcolor(YELLOW);
	k.draw(100,100,300,100,it);					setcolor(LIGHTMAGENTA);
	k.draw(300,100,200,266,it);
		delay(600);
		it++;
	cleardevice();
		}

	
	getch();
	
	closegraph();
}
