#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class kochCurve{
    public:
    void koch(int x1,int y1,int x2,int y2,int itr){
        int x,y,x3,y3,x4,y4;
        int dx,dy;
        float ang=60*(3.14/180);
        if(itr==0){
            line(x1,y1,x2,y2);
        }
        else{
//            delay(10);
            //dx=(x-x1)/3;
            //dy=(y-y1)/3;
            x3=((2*x1)+x2)/3;     y3=((2*y1)+y2)/3;
            x4=(x1+(2*x2))/3;     y4=(y1+(2*y2))/3;
            x=x3+(x4-x3)*cos(ang)+(y4-y3)*sin(ang);
            y=y3-(x4-x3)*sin(ang)+(y4-y3)*cos(ang);
            koch(x1,y1,x3,y3,itr-1);
            koch(x3,y3,x,y,itr-1);
            koch(x,y,x4,y4,itr-1);
            koch(x4,y4,x2,y2,itr-1);
        }
    }
};
int main()
{
    kochCurve k;
    int it;
    cout<<"Enter no. of iterations :";
    cin>>it;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    k.koch(200,266,100,100,it);
    k.koch(100,100,300,100,it);
    k.koch(300,100,200,266,it);
    getch();
//    delay(1);
    closegraph();
    return 0;
}
