#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class transform
{
	public:
		
		int m, a[20][3], c[20][3];
		int i, j, k;
		
		void object();
		void accept();
		
		void operator * (float b[20][20])
		{
			for(i=0; i<m; i++)
			{
				for (j=0; j<m; j++)
				{
					c[i][j] = 0;
					
					for(k=0; k<m; k++)
					
							 c[i][j] += a[i][k]* b[k][j];
				}
			}
		}
		
};

void transform::object() 
{
	int gd = DETECT, gm;	
	initgraph(&gd, &gm, NULL);
	
	int x = 640;
	int y = 480;
	cout << "X : " << x << endl << "y: "<<y<<endl;
	setcolor(12);
	line(0,y/2,x,y/2);			   			  		 	// x axis
	line(x/2,0,x/2,y);
	x /=2;
	y /=2;
	cout << "X : " << x << endl << "y: "<<y<<endl;
	for(i=0; i<m-1; i++)
	{
		line(x + a[i][0], y - a[i][1], x + a[i+1][0], y - a[i+1][1]);
	}
	 	line(x + a[0][0], y - a[0][1], x + a[i][0], y - a[i][1]);
	 	
	 	setcolor(YELLOW);
	for(i=0; i<m-1; i++)
	{
		line(x + c[i][0], y - c[i][1] , x + c[i+1][0], y - c[i+1][1]);
	}
	 line(x+c[0][0], y - c[0][1], x+c[i][0], y - c[i][1]);
//	getch();
	
	int temp;
	cout << "Press 1 to continue ...\n";
	cin >> temp;
	closegraph();
}

void transform::accept() 
{
	cout << "Enter number of edges : ";
	cin >> m;
	
	cout << "Enter the coordinates : ";
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<3; j++)
		{
			if (j >=2)
			   a[i][j] = 1;
            else
                cin >> a[i][j];
		}
	}
}

int main()
{
    float tx, ty, sx, sy;
    int ch;
    
    float deg , b[20][20];
	transform t;
	t.accept() ;
	
	do
	{

	    cout << endl << "1-Translation\n2-Scaling\n3-Rotation\n";
	    	    cout << "Enter your choice : ";
	    cin >> ch;
	    
	    switch(ch)
	    {
	        case 1:
	            
	            cout << "\nTRANSLATION OPERATION\n";
	            cout << "tx : ";
	            cin >> tx;
	            cout << "ty : ";
	            cin >> ty;
	            
	            b[0][0] = b[1][1] = b[2][2] = 1;
	            b[0][1] = b[0][2] = b[1][0] = b[1][2] = 0;
	            b[2][0] = tx;
	            b[2][1] = ty;
	            
	            t*b;
	            
	            t.object() ;
	            
	            break;
	            
            case 2:
                
                cout << "\nSCALING OPERATION\n";
                cout << "sx : ";
                cin >> sx;
                cout << "sy : ";
                cin >> sy;
                
                b[0][0] = sx;
                b[1][1] = sy;
                
                b[2][2] = 1;
                
                b[0][1] = b[0][2] = b[1][0] = b[1][2] = b[2][0] = b[2][1] = 0;
                
                t*b;
                t.object();
                break;
	            
            case 3:
                
                cout << "\nROTATION OPERATION\n";
                cout << "angle : ";
                cin >> deg;                
                
                deg = deg * M_PI / 180;
                
                b[0][2] = b[2][0] = b[1][2] = b[2][1] = 0;
                b[2][2] = 1;
                b[0][0] = b[1][1] = cos(deg);
                b[0][1] = sin(deg);
                b[1][0] = -1 * b[0][1];
                
                t* b;
                
                t.object() ;
                break;
            default:
                cout << "Invalid\n";
        }
    }
    while(ch != 4);
    
    getch();
}
