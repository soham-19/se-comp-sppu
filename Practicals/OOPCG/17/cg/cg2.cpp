#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
int gd,gm;
gd= DETECT;
initgraph(&gd,&gm,NULL);
putpixel(100,100,RED);
setcolor(YELLOW);
rectangle(50,150,350,450);
setcolor(BLUE);
line(50,300,200,150);
line(200,150,350,300);
line(350,300,200,450);
line(200,450,50,300);
setcolor(WHITE);
circle(200,300,105);
delay(30000);
closegraph();
return 0;
}

