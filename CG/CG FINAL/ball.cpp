#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void disp(int n,float c[][3])
{
	float maxx,maxy;
	int i;
	maxx=getmaxx();//TO GET MAXIMUM X COORDINATE VALUE
	maxy=getmaxy();//TO GET MAXIMUM Y COORDINATE VALUE
	maxx=maxx/2;
	maxy=maxy/2;
	i=0;//draw polygon
	while(i<n-1)
	{
	     line(maxx+c[i][0],maxy-c[i][1], maxx+c[i+1][0],maxy-c[i+1][1]);
	     i++;
	}
	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1], maxx+c[0][0],maxy-c[0][1]);

	//draw xy-axis
	setcolor(GREEN);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
}
void mul(int n,float b[][3],float c[][3],float a[][3])
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			a[i][j]=0;		//INITIALIZE ALL COORDINATES AS 0
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
			{
				a[i][j] = a[i][j] + (c[i][k] * b[k][j]);
			}
}
void translation(int n,float c[][3],float tx,float ty)
{
	float b[10][3],a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;

	b[0][0]=1;
	b[1][1]=1;
	b[2][0]=tx;
	b[2][1]=ty;
	b[2][2]=1;

	mul(n,b,c,a);
	setcolor(RED);
	disp(n,a);
	getch();
}



void scaling(int n,float c[][3],float sx,float sy)
{
	float b[10][3],a[10][3];
	int i=0,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=sx;
	b[1][1]=sy;
	b[2][2]=1;

	mul(n,b,c,a);
	setcolor(RED);
	disp(n,a);
	getch();
}
void rotation(int n,float c[][3],float ra)
{
	int i=0,j;
	float b[10][3],xp,yp,a[10][3];
	xp=c[0][0];
	yp=c[0][1];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			b[i][j]=0;
	b[0][0]=b[1][1]=cos(ra*3.14/180);
	b[0][1]=sin(ra*3.14/180);
	b[1][0]=-sin(ra*3.14/180);
	b[2][0]=(-xp*cos(ra*3.14/180))+(yp*sin(ra*3.14/180))+xp;
	b[2][1]=(-xp*sin(ra*3.14/180))-(yp*cos(ra*3.14/180))+yp;
	b[2][2]=1;
	mul(n,b,c,a);
	setcolor(RED);
	disp(n,a);
}
int main()
{
	int i,j,k,ch,n,gd=DETECT,gm;
	float c[10][3],tx,ty,sx,sy,ra;
	initgraph(&gd,&gm,NULL);
	cout<<"\nEnter the number of vertices :";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\nEnter the co-ordinates of the vertex"<<i+1<<":";
		cin>>c[i][0]>>c[i][1];
		c[i][2]=1;
	}
	do
	{
		
		cleardevice();
		cout<<"\n\t\t\t * * * MENU * * *";
		cout<<"\n\t 1) TRANSLATION";
		cout<<"\n\t 2) SCALING";
		cout<<"\n\t 3) ROTATION";
		cout<<"\n\t 4) EXIT";
		cout<<"\n\t ENTER YOUR CHOICE:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n\tEnter translation factor for X & Y axis :\t";
			cin>>tx>>ty;
			cleardevice();
			setcolor(BLUE);
			disp(n,c);
			translation(n,c,tx,ty);
			getch();
			break;
		case 2:
			cout<<"\n\tEnter scaling factor for X & Y axis :\t";
			cin>>sx>>sy;
			cleardevice();
			setcolor(BLUE);
			disp(n,c);
			scaling(n,c,sx,sy);
			break;
		case 3:
			cout<<"\n\n\tEnter the angle of rotation:\t";
			cin>>ra;
			cleardevice();
			setcolor(BLUE);
			disp(n,c);
			rotation(n,c,ra);
			getch();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"\n\tInvalid choice !!";
			break;
		}
	}	while(ch<4);
	getch();
	delay(2000);
	closegraph();
	return 0;
}
