#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class Scan{
    
    public :
        
        int x[20], y[20], i, j, k, minPos, p, n;
        float xi[20], slp[20], dx, dy;
        
        void getC(int a)
        {
            n = a;
            for(i=0; i<n; i++){
                cout << "x"<<i+1<<",y"<<i+1<<": ";
                cin >> x[i] >> y[i];
            }
            x[i] = x[0];
            y[i] = y[0];
        }
        
        void drawP(){
            for(i=0; i<n;i++)
                     line(x[i+1],y[i+1],x[i],y[i]);
        }
};

class poly : public Scan{
    public:
        
        poly(int a){
            this->getC(a);
            this->drawP();
        }
        
        void getS(){
            for(i=0; i<n; i++)
            {
                dy = y[i+1] - y[i];
                dx = x[i+1] - x[i];
                
                if (dy==0)  slp[i] = 1;
                else if (dx == 0)       slp[i] = 0;
                else slp[i] = dx/dy;
            }
        }
        
        void getX()
        {    
             k=0;
            for( i=0; i<n; i++){
                
                if ( (y[i] <= p && y[i+1] > p) || (y[i] >p && y[i+1] <= p) )
                     
                     xi[k++] = x[i] + slp[i] * (p-y[i]);
            }
        }
        
        void sortX(){
            for(i=0; i<k; i++){
                minPos = i;
                for(j=i+1; j<k; j++){
                    if(xi[j] < xi[minPos])
                             minPos = j;
                }
                swap(xi[minPos],xi[i]);
            }
        }
        
        void fill()
        {
            getS();
            for(p=0; p<480; p++){
                
                getX();
                sortX();
                
                for(i=0; i<k; i+=2){
                    line(xi[i], p, xi[i+1],p);
                    delay(15);
                }
            }
        }
};

int main(){
    int n;
    cin >> n;
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    setcolor(14);
    poly P(n);
    setcolor(12);
    P.fill() ;
    
    getch();
    
    closegraph();
    
}
