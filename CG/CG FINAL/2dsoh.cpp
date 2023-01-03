#include<iostream>
#include<graphics.h>
#include <math.h>
using namespace std;

class transform {
	
	float a[20][20], c[20][20];int i, j, k, m;
	float tx, ty, sx, sy, angle, b[20][20];
	
	public:
		void operator* (float b[20][20])
		{
			for(i=0; i<m; i++)
			{
				for(j=0; j<m; j++)
				{
					c[i][j] = 0;
					
					for(k=0; k<m; k++)
						c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		void accept()
		{
			cout << "Enter number of edges : ";
			cin >> m;
			
			for (i=0; i<m; i++){
				for(j=0; j<m; j++){
					if(j>=2)
						a[i][j] = 1;
					else{
						cout << "-> ";
						cin >> a[i][j];
					}
				}
			}
		}
		
		void object()
		{
			int gd = DETECT, gm;
			initgraph(&gd,&gm,NULL);
			setcolor(LIGHTGREEN);
			
			int maxx = 640, maxy = 480;
			
			line(0,maxy/2,maxx,maxy/2);
			line(maxx/2,0,maxx/2,maxy);
			maxx /= 2; maxy /=2;
			setcolor(LIGHTRED);
			
			
			for(i=0; i<m-1; i++)
				line (maxx + a[i][0], maxy - a[i][1], maxx + a[i+1][0], maxy - a[i+1][1] ) ;
				
				line( maxx + a[0][0], maxy - a[0][1], maxx + a[i][0], maxy - a[i][1] );
				
setcolor(YELLOW);
//line(1,100,0,100);
//cout<<"hiiiiiiiii";
			
			for(i=0; i<m-1; i++)
				line (maxx + c[i][0], maxy - c[i][1], maxx + c[i+1][0], maxy - c[i+1][1] ) ;
				
				line( maxx + c[0][0], maxy - c[0][1], maxx + c[i][0], maxy - c[i][1] );
			
			cout << "Press 1 to continue : ";
			int temp;
			cin >> temp;
			closegraph();
		}
};

main(){
	float tx,ty,sx,sy,ang;
	transform t;
	t.accept ();
	int ch = 40;
	float b[20][20];
	while(ch != 4)
	{
		cout << "MAIN MENU\n1-translation\n2-scaling\n3-rotation\n->\t";
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "TRANSLATION\n";
				
				cout << "TX TY   ";
				cin >> tx >>ty;
				b[0][0] = b[1][1] = b[2][2] = 1;
				b[2][0] = tx;  b[2][1] = ty;
				b[0][1] = b[0][2] = b[1][0] =  b[1][2] = 0;
				
				t*b;
				t.object() ;
				break;
			case 2:
				cout << "SCALING\n";
				cout << "SX : SY : ";
		
				cin >> sx >> sy;
				b[0][0] = sx ;  b[1][1] = sy;
				b[2][2] = 1;
				b[0][1] = b[0][2] = b[1][0] =  b[1][2] = b[2][0] = b[2][1] = 0;
				t * b;
				t.object() ;
				break;
				
			case 3:
				cout << "ROTN\n";
				cout << "ang : ";
			
				cin >> ang;
				ang = ang*M_PI/180;
				b[0][0] = b[1][1] = cos(ang);
				b[2][2] = 1;
				b[0][1] = sin(ang);
				b[1][0] = -1* b[0][1];
				b[0][2] = b[1][2] = b[2][0] = b[2][1] = 0;
				
				t * b;
				t.object() ;
				break;	
			default:
				cout <<"!!!!!!!!!!!!!!!!!!11\n"			;
		}
		getch();
	}
}
