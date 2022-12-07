#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);
setcolor(RED);
line(120,240,320,40);
line(320,40,520,240);
line(520,240,320,440);
line(320,440,120,240);
setcolor(BLUE);
circle(320,240,140);
setcolor(GREEN);
rectangle(120,40,520,440);
delay(100000);
closegraph();
return 0;

}



