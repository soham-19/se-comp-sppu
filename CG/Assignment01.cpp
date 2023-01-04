#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class Scan
{
	public:
		int x[20], y[20], p, k, n, i, j, m;
		float slp[20], xi[20], dx, dy;
		
		void getC(int a)
		{
			n = a;
			
			for(i=0; i<n; i++)
			{
				cout << "x"<<i+1<<",y"<<i+1<< " : ";
				cin >> x[i] >> y[i];
			}
			x[n] = x[0];
			y[n] = y[0];
		}
		
		void drawP()
		{
			for (int i=0; i<n; i++)
			{
				line(x[i], y[i], x[i+1], y[i+1]);
			}
		}
};

class poly: public Scan
{
	public:
		poly(int a)
		{
			this->getC(a) ;
			this->drawP() ;
		}
		
		void cS()
		{
			for(i=0; i<n; i++)
			{
				dx = x[i+1] - x[i];
				dy = y[i+1] - y[i];
				
				if (dy==0)	slp[i] = 1;
				else if (dx==0)	slp[i] = 0;
				else 		slp[i] = dx/dy;
			}
		}
		
		void getX()
		{
			k = 0;
			for(i=0; i<n; i++)
			{
				if ( ( y[i] <= p && y[i+1]>p ) || (y[i] >p && y[i+1] <= p))
				{
					xi[k++] = x[i] + slp[i] * (p-y[i]);
				}
			}
		}
		
		void sortX()
		{
			for(i=0; i<k; i++)
			{
				m = i;
				for(j=0; j<k;j++)
				{
					if(xi[j] < xi[m])
						m = j;
				}
				
				swap(xi[m],xi[j]);
			}
		}
		
		void fillP()
		{
			this->cS() ;
			
			for(p=0; p<480; p++)
			{
				this->getX() ;
				this->sortX() ;
				for(i=0; i<k; i+=2)
				{
					line(xi[i],p,xi[i+1],p);
					delay(15);
				}
			}
		}
};

main(){

int gd = DETECT, gm;
initgraph(&gd,&gm,NULL);
setcolor(12);
	poly *P = new poly(3);
	setcolor(YELLOW);
	P->fillP();
	getch();
closegraph();
}
