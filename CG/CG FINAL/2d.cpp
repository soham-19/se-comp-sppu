#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class transform{
    
    public:
        int a[20][20], c[20][20], m, i, j, k;
        float b[20][20], tx, ty, sx, sy, angle;
        
//        void object();
        
        void operator *= (transform B){
            
            for(i=0; i<m; i++){
                for(j=0;j<m;j++){
                	c[i][j] = 0;
                    for(k=0;k<m;k++)
                    	c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        
        void setBMat(int op)
        {
        	if (op==1)
        	{
        		// translation 
        		b[0][0] = b[1][1] = b[2][2] = 1;
        		b[2][0] = tx;	b[2][1] = ty;
        		b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
			}
			
			else if (op ==2)
			{
				b[0][0] = sx;	b[1][1] = sy;
				b[2][2] = 1;
				b[0][1] = b[0][2] = b[1][0] = b[1][2] = b[2][0] = b[2][1] = 0;
			}
			else{
				b[0][2] = b[2][0] = b[1][2] = b[2][1] = 0;
				b[2][2] = 1;
				b[0][0] = b[1][1] = cos(angle);
				b[0][1] = sin(angle);
				b[1][0] = sin(-1*angle);
			}
		}
		void setB(){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					b[i][j] = 0;
				}
			}
		}
		void accept()
		{
			cout << "ENter no. of edges : ";
			cin >> m;
			for(i=0; i<m; i++){
				for(j=0; j<m; j++){
					if(j>=2)
						a[i][j] = 1;
					else
					{
						cout << "-> : ";
						cin >> a[i][j];
					}
				}
			}
		}
		
		void object()
		{
			int maxx = 640, maxy = 480;
			
			int gd = DETECT, gm;
			initgraph(&gd,&gm,NULL);
			setcolor(YELLOW);
			line(0,maxy/2,maxx,maxy/2);
			line(maxx/2,0,maxx/2,maxy);
			
			setcolor(CYAN);						maxx/=2; maxy /=2;
			
			for(i=0; i<m-1; i++)
				line(maxx + a[i][0], maxy - a[i][1], maxx + a[i+1][0], maxy - a[i+1][1]);
			
				line(maxx + a[0][0], maxy - a[0][1], maxx + a[i][0], maxy - a[i][1]);
				
				
			setcolor(LIGHTRED);
			
			for(i=0; i<m-1; i++)
				line(maxx + c[i][0], maxy - c[i][1], maxx + c[i+1][0], maxy - c[i+1][1]);
				
				line(maxx+ c[i][0], maxy-c[i][1], maxx + c[0][0], maxy - c[0][1]);
				
			cout << "press 1 to continue : ";
			int temp;
			cin >> temp;
			closegraph();
		}
};

main()
{
	transform t;
	t.accept() ;
//	t.object() ;
	
	int ch = 1;
	
	while(ch != -1)
	{
		cout << "MAIN MENU\n1-translation\n2-scaling\n3-rotation\n-->\t";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "TRANSLATION : \n";
				cout << "tx : ";
				cin >> t.tx ;
				cout << "ty : ";
				cin >> t.ty;
				t.setBMat(1);
				t*=t;
				t.object() ;
				break;
				
			case 2:
				cout << "SCALING : \n";
				cout << "sx : ";
				cin >> t.sx;
				cout << "sy : ";
				cin >> t.sy;
				t.setB();
				t.setBMat(2);
				t*=t;
				t.object() ;
				break;
				
			case 3:
				cout << "ROTATION : \n";
				cout << "angle : ";
				cin >> t.angle;
				t.angle = t.angle  * M_PI / 180;
				t.setBMat(3);	
									t*=t;
				t.object() ;
				break;
			
			default :
						cout << "INVALID\n"			;
		}
	}
	
	getch();
}
