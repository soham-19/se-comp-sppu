#include <iostream>
#include <graphics>
using namespace std;
class line_s
{
	float x1,x2,y1,y2,length;
	public:
	line_s()
	{
	cout<<"Enter the values of x1,x2,y1,y2 resply:"<<endl;
	cin>>x1>>x2>>y1>>y2;
	}
void funline()
{
int Dx=x2-x1;
int Dy=y2-y1;
if(abs(Dx)>=abs(Dy))
	{
	length=abs(Dx);
	}
else
{
length=abs(y2-y1)
}
float dx=Dx/length;
float dy=Dy/length;
float x=x1,y=y1;
int i=0;
while (i<=length)
{
	putpixel(floor(x),floor(y),3);
	x=x+dx;
	y=y+dy;
	i++;
}
}
};	
int main()
{
int gd,gm;
	gd=DETECT;
	initgraph (&gm,&gd,NULL);
	line_S1[3];
	for(int j=0;j<3;j++)
	{
		S1[j].funline();
	}
	delay(5000)
	closegraph();
	return 0;

}



