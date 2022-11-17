#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void DDA_line(int x1,int y1,int x2,int y2,int icolour)
{
	int i;
	float dx,dy,steps,xinc,yinc,X,Y;
	dx=(x2-x1);
	dy=(y2-y1);
	if (fabs(dx)>fabs(dy))
{
	steps=fabs(dx);
}
else
{
	steps=fabs(dy);
}
xinc=dx/steps;
yinc=dy/steps;
X=x1;
Y=y1;
for (i=0;i<steps;i++)
{
	putpixel(floor(X),floor(Y),icolour);
	X=X+xinc;
	Y=Y+yinc;
}
}

main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	DDA_line(400,150,200,300,RED);

	delay(10000);
	closegraph();

}






