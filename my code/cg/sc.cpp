#include<iostream>
#include<graphics.h>
using namespace std;
int main() {
	
	int n, i, j, k, gd, gm, dx, dy;
	int x, y, temp;
	int a[20][2], xi[20];
	float slope[20];
	
	cout<<"Enter number of vertices"<<endl;
	cin>>n;
	
	cout<<"Enter the coordinates"<<endl;
	
	for(int i=0; i<n; i++){
		
		cout<<"X"<<i+1<<"\t";
		cin>>a[i][0];
		cout<<"Y"<<i+1<<"\t";
		cin>>a[i][1];		
	}
	
	a[n][0] = a[0][0];
	a[n][1] = a[0][1];
	
	detectgraph(&gd, &gm);
	initgraph(&gd, &gm, NULL);
	
	setcolor(12);
	
	for(int i=0; i<n; i++)
		line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
		
	for(int i=0; i<n; i++){
		
		dy = a[i+1][1] - a[i][1];
		dx = a[i+1][0] - a[i][0];
		
		if(dy == 0)		slope[i] = 1.0;
		else if(dx == 0)		slope[i] = 0.0f;
		
		else
			slope[i] = (float) dx/dy;
		
		
	}
	
	for(y=0; y<480; y++){
		
		k = 0;
		
		for(i=0; i<n; i++) {
			
			if( ( (a[i][1] <= y) && (a[i+1][1] >y) ) || ( (a[i+1][1] > y) && (a[i][1] <= y) ) ) {
				
//				xi[k] = a[i][0] + slope*(y-a[i][1]);
				int b = int(slope*(y-a[i][1]) + a[i][0]);
				k++;
				
			}
		}
		
		for(j=0; j<k-1;j++){
			for(i=0; i<k-1; i++){
				
				if(xi[i] > xi[i+1])
				{
					temp = xi[i];
					xi[i] = xi[i+1];
					xi[i+1] = temp;
				}
			}
			
			setcolor(35);
			
		}
		
		for(i=0; i<k;i+=2){
			
			line(xi[i],y,xi[i+1],y);
		}
	}
	
	delay(10000);
	
	closegraph();
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
}
