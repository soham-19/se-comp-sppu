// Cohen - Sutherland Line Clipping Algorithm
#include <iostream>
#include <graphics.h>
using namespace std;

class clip
{
	private:
		float x1, y1, x2, y2, x, y, xl, yl, xh, yh;
		
	public:
		int T = 8;
		int B = 4;
		int L = 1;
		int R = 2;
		int outCode (int x, int y)
		{
			int code = 0;
			if (y > yh)
			{
				code = code | T;
			}
			if (y < yl)
			{
				code = code | B;
			}
			if (x > xh)
			{
				code = code | R;
			}
			if (x < xl)
			{
				code = code | L;
			}
			return code;
		}
		void lineClip()
		{
			int code1, code2;
			cout<<"\nEnter the botttom left and upper right coordinate of the rectangle : ";
			cin>>xl>>yl>>xh>>yh;
			
			setcolor(BLUE);
			rectangle(xl, yl, xh, yh);
	
			cout << "\n---Line Coords---\n";
			cout << "Enter x1, y1: ";
			cin >> x1 >> y1;
			cout << "Enter x2, y2: ";
			cin >> x2 >> y2;
	
			setcolor(WHITE);
			line(x1, y1, x2, y2);
			delay(1500);
			int temp, flag = 0;
			float m;
	
			code1 = outCode(x1, y1);
			code2 = outCode(x2, y2);
			while (1)
			{
				m = (float)(y2 - y1) / (x2 - x1);
		
				if (code1 == 0 && code2 == 0)
				{
					flag = 1;
					break;
				}
				else if ((code1 & code2) != 0)
				{
					break;
				}
				else 
				{
					if(code1 == 0)
					{
						temp = code2;
					}
					else
					{
						temp = code1;
					}

					if(temp & T)
					{
						x = x1 + (yh-y1)/m;
						y = yh;
					}
					else if(temp & B) 
					{
						x = x1 + (yl-y1)/m;
						y = yl;	
					}	
					else if(temp & L)
					{
						y = y1 + m*(xl-x1);
						x = xl; 	
					}
					else if (temp & R)
					{
						y = y1 + m*(xh-x1);
						x = xh; 	
					}
					if(temp == code1)
					{
						x1 = x;
						y1 = y;
						code1 = outCode(x1,y1);  
					}		
					else 
					{	
						x2 = x;
						y2 = y;
						code2 = outCode(x2,y2);
					}
				 }
			}
			delay(10000);
			cleardevice();
			settextstyle(10, 0, 2);
			outtextxy(180, 20, "Line Successfully Clipped");
			rectangle(xl, yl, xh, yh);
			setcolor(YELLOW);
	
			if (flag == 1)
			{
				line(x1, y1, x2, y2);
				delay(5000);
			}
	
			closegraph();
		}
};

//int clip::outCode(int x, int y)	// Called by lineClip() so returns outcode to lineClip()

//void clip::lineClip()

int main()
{
	clip c1;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	c1.lineClip();
	getch();
	delay(5000);
	return 0;
}
