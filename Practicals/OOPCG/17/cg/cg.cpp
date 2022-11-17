#include <iostream>
#include <graphics.h>                                                     
using namespace std;
int main()
{
int gd, gm;
gd= DETECT;
initgraph(&gd ,&gm ,NULL);
putpixel(100,100,RED);
setcolor(BLUE);
line(50,50,100,100);
circle(100,100,50);
rectangle(50,150,250,200);
delay(5000);
closegraph();
return 0;
}  



