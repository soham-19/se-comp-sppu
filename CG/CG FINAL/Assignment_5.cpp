#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class Koch
{
    float ang;
    
    public:
        Koch(){
            ang = 60 * M_PI/180;
        }
        
        void draw(int x1, int y1, int x2, int y2, int it){
            int x3,y3,y4,x4,x,y;
            if(it==0)
                     line(x1,y1,x2,y2);
                     
            else{
                
                 x3 = (2*x1+x2)/3;
                 y3 = (2*y1+y2)/3;
                 x4 = (x1+2*x2)/3;
                 y4 = (y1+2*y2)/3;
                
                 x = x3 + (x4-x3)*cos(ang) + (y4-y3)*sin(ang);
                 y = y3 - (x4-x3)*sin(ang) + (y4-y3) * cos(ang);
                
                draw(x1,y1,x3,y3,it-1);  //              delay(10);
                draw(x3,y3,x,y,it-1);             //   delay(10);
                draw(x,y,x4,y4,it-1);          //      delay(10);
                draw(x4,y4,x2,y2,it-1);
                delay(25);
            }
        }
};

main(){
    int it,itr;
    cin >> itr;
    it = 0;
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    
                            
    Koch k;
    
    while(it<=itr)
    {             setcolor(LIGHTMAGENTA);
    k.draw(200,266,100,100,it) ;         setcolor(LIGHTRED);
    
    k.draw(100,100,300,100,it) ;         setcolor(LIGHTGREEN);
    k.draw(300,100,200,266,it) ;
    it++;
        delay(1000);
    cleardevice();

    }

    
    getch();
    closegraph();
}
