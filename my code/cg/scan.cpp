#include<iostream>
#include<graphics.h>
using namespace std;

int main(){
	int n, i, j, k, gd, gm, dy, dx, x, y, temp;
	
	int a[20][2] , xi[20][2];
	
	float slope[20][20];
	
	std::cout << "no of edges\t";
	cin>>n;
	cout << "enter coordinates\n";
	
	for(int i=0; i<n; i++){
		
		cout<<"\tX"<<i+1<<" Y"<<i+1<<" : ";
		
		cin>>a[i][0];
		cin>>a[i][1];
	}
	a[n][0] = a[0][0];
	a[n][1] = a[0][1];
	
	
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	
	for(int i=0; i<n; i++)
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
		
	for(int i=0; i<n; i++){
		
		dy = a[i+1][1] - a[i][1];
		dx = a[i+1][0] - a[i][0];
	
	if(dy==0)	slope[i] = 1.0;
	if(dx==0)   slope[i] = 0.0;
	
	if(dy !=0 && dx != 0)
		slope[i] = (float)dx/dy;
		
	}
	
	
	delay(100000);
	
	closegraph();
}
