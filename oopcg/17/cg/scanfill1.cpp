#include <iostream>
#include <graphics.h>
using namespace std;

class line_1
{
    public:
        void drawline(int x1,int y1,int x2, int y2)
        {
            line(x1,y1,x2,y2);
        }
};


class polygon:public line_1
{
    int xx[10],yy[10],n,inx[10],ymax,ymin;
    public:
        void accept()
        {
            int i;
            int gd =DETECT, gm=0;
            cout<<"Enter the Number of sides of Polygon:-";
            cin>>n;
            for(i=0;i<n;i++)
            {
                cout<<"\nEnter the co-ordinates of Polygon =";
                cin>>xx[i];
                cin>>yy[i];
            }

            xx[i]=xx[0];
            yy[i]=yy[0];

            initgraph(&gd,&gm,NULL);
            for(i=0;i<=n-1;i++)
            {
                drawline(xx[i],yy[i],xx[i+1],yy[i+1]);
            }
        }

        void scanline()
        {
            int i,k,temp,y;
            ymax=0;
            ymin=500;
            float m[50],dx,dy;
            setcolor(BLUE);
            for(i=0;i<n;i++)
            {
            if(yy[i]>=ymax)
            ymax=yy[i];
            if(yy[i]<=ymin)
            ymin=yy[i];

            dx=xx[i+1]-xx[i];
            dy=yy[i+1]-yy[i];

            if(dx==0)
            m[i]=0;
            if(dy==0)
            m[i]=1;

            if(dx!=0 && dy!=0)
            m[i]= (float) (dx/dy);
            }

            for(y=ymax;y>=ymin;y--)
            {
                int c = 0;
                for(i=0;i<n;i++)
                {
                    if((yy[i]>y&&yy[i+1]<=y) || (yy[i]<=y&&yy[i+1]>y))
                    {
                        inx[c]=(xx[i]+(m[i] * (y-yy[i])));
                        c++;
                    }
                }

                for(k=0;k<c-1;k++)
                {
                    for(i=0;i<c-1;i++)
                    {
                        if(inx[i]>inx[i+1])
                        {
                            temp = inx[i];
                            inx[i] = inx[i+1];
                            inx[i+1] = temp;
                        }
                    }
                }

                for(i=0;i<c-1;i+=2)
                {
                    drawline(inx[i],y,inx[i+1],y);
                    delay(100);
                }
            }
        }
};

int main()
{
    polygon p;
    p.accept();
    p.scanline();
    getch();
    closegraph();
    return 0;
}

	

