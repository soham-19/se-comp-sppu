#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class scan
{
    public:
    int x[20],y[20],k;
    float slope[20],x_int[20];
    void polygon(int n);
};

void scan::polygon(int n)
{
    int i;
    float dx,dy;
   
    x[n]=x[0];
    y[n]=y[0];
    for(int i=0;i<n;i++)  
    {  
       
            line(x[i],y[i],x[i+1],y[i+1]);  
    }
   
    for(i=0;i<n;i++)  
    {
        dy=y[i+1]-y[i];  
        dx=x[i+1]-x[i];  
        if(dy==0)
        slope[i]=1;
        else if(dx==0)
        slope[i]=0;
        else
        slope[i]=dx/dy;
    }
    for(int p=0;p<400;p++)
    {
        k=0;
        for(i=0;i<n;i++)
        {
            if(( (y[i]<=p) && (y[i+1]>p)) || ((y[i]>p) && (y[i+1]<=p) ))
              {
                  x_int[k]=x[i]+slope[i]*(p-y[i]);    
                  k++;
              }
          }
         
          for(int j=0;j<k-1;j++)  
          {
              for(int i=0;i<k-1;i++)
              {
                  if(x_int[i]>x_int[i+1])  
                  {
                      int temp = x_int[i];
                      x_int[i] = x_int[i+1];
                      x_int[i+1] = temp;
                  }
              }
          }
         
          for(int i=0;i<k;i=i+2)  
          {
               setcolor(RED);

              line(x_int[i], p ,x_int[i+1], p);  
              delay(10);      
          }
         
          }
  }
        int main()
  {
int n,i;
scan p;
      cout<<"\nEnter the number of vertices of Polygon:\n";
      cin>>n;
        cout<<"\nEnter the co-ordinates Polygon:\n";
        for(i=0;i<n;i++)
         {
          cin>>p.x[i]>>p.y[i];
         }
      int gd,gm;
      gd=DETECT;
      initgraph(&gd,&gm,NULL);
     
      p.polygon(n);
      getch();
      closegraph();
      return 0;
}


