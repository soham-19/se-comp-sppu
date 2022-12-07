#include<iostream>
#include<graphics.h>
using namespace std;
class Cohen
{
          private:
          int xl,xh,yl,yh;
                    
          int CENTER=0,TOP=8,LEFT=1,RIGHT=2,BOTTOM=4;
          public:
          int code1;
          int code2;
          int code3;
          int code4;
          
          void get();
          void process();
};
void Cohen::get()
{
          cout<<"enter the co-ordinate of rectangle:";
          cin>>xl>>yl;
          cout<<"enter the co-ordinate of other end point of rectangle:";
          cin>>xh>>yh;
          rectangle(xl,yl,xh,yh);
          cout<<"enter the line co-ordinate:";
          cin>>x2>>y2>>x3>>y3;
          line(x2,y2,x3,y3);
}
void Cohen::process()
{
          if(xl>x2)
          {       
             code1 |= BOTTOM;
             break;
          }
          else if(xh<x3)
          {
                    code2 |=TOP;
                    break;
          }
          else if(yl>y2)
          {
                    code3 |=LEFT;
                 break;
          }
          else if(yh<y3)
          {
                    code4 |=RIGHT;
                  break;
          }
             
          else
          {       
                    int flag=0;
                    if(code1 && code2)
                    {
                          flag=0;
                          
                    }
                     if(code1 && code2)
                     {
                          flag!=0;
                         
                     }
          }
               
          int flag=0;
          int out;
	while (1) 
	{
		if ((code1 == 0) && (code2 == 0)) 
		{
			
			flag=1;
			break;
		}
		else if (code1 & code2) 
		{
		          flag=0;
			break;
		}       
		if (code1 != 0)
	          {       
                              out = code1; 
                    }
		else
                    {
                              out = code2;
                    }
                    if(code2!=0)
                    {
                              out=code1;
                    }
                    else
                    {
                               out=code2;
                    }
          }
}
int main()
{ 	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	
	putpixel(100,100,RED);
	
	setcolor(YELLOW);
	
	Cohen obj;
	obj.get();
	obj.process();
			
	delay(10000);
	closegraph();
	return 0;
}

	
          
          
         
