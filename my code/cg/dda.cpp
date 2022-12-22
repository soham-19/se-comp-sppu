#include<iostream>
#include<math.h>
#include<graphics.h>

int sign(int a){
	if(a<0)
		return -1;
	else if(a>0)
		return 1;
		
	return 0;
}

void dda(int x1, int y1, int x2, int y2, int col) {
	
	int Dx = (x2-x1);
	int Dy = (y2-y1);
	int len, i;
	
	if(abs(Dx) >= abs(Dy))
		len = abs(Dx);
	else 
		len = abs(Dy);
		
	int x_inc = Dx/len;
	int y_inc = Dy/len;
	
	int x = x1 + 0.5 * sign(Dx);
	int y = y1 + 0.5 * sign(Dy);
	
	for(int i=0; i<len;i++)
	{
		putpixel(x,y,col);
		x = x + x_inc;
		y = y + y_inc;
		delay(50);
	}
}

int main(){
	
	int gm, gd;
	gd = DETECT;
	
	int a,b,c,d;
	std::cout << "points\n";
	std::cin>>a>>b>>c>>d;
	initgraph(&gd,&gm,NULL);
	dda(a,b,c,d,12);
		delay(3000000);
	closegraph();

}
