#include<iostream>
 #include<graphics.h>
using namespace std;

class poly{
	
	int x_c[10], y_c[10], n, k, x_intc[10], y_min, y_max;
	float slope[10];
	
	public:
		poly(){
		}
		void getPoly();
		void drawPoly();
		void getSlopes();
		void scan();
};

void poly::getPoly(){

	cout << "Enter the number of vertices\t";
	cin >> n;

	if(n<3){
		cout << "Polygon can't be formed\n";
		exit(0);
	}
	else {
		for( int i=0; i<n; i++){
			cout << "X" << i + 1 << " " << "Y" << i + 1 << " : ";
			cin >> x_c[i] >> y_c[i];
		}

		x_c[n] = x_c[0];
		y_c[n] = y_c[0];
	}
}

void poly::drawPoly(){
	setcolor(6);
	
	for(int i=0; i<n; i++) {
		line(x_c[i], y_c[i], x_c[i+1], y_c[i+1]);
	}
}

void poly::getSlopes(){
		
	for(int i=0; i<n; i++){
		
		float dy = y_c[i+1] - y_c[i];
		float dx = x_c[i+1] - x_c[i];
		
		if(dy == 0)		
			slope[i] = 1.0;

		else if(dx == 0)		
			slope[i] = 0.0;
		
		else
			slope[i] = dx/dy;
	}
}

void poly::scan() {

	for (int sl = 0; sl<480; sl++){

		k = 0;

		for( int i=0; i<n; i++) {

			if( ( (y_c[i]<=sl)&&(y_c[i+1]>sl) ) || ( (y_c[i]>sl)&&(y_c[i+1]<=sl) ) ) {

				x_intc[k] = x_c[i] + slope[i] * (sl - y_c[i]);
				k++;
			}
		}

        for (int j = 0; j < k - 1; j++)
        {
            for (int i = 0; i < k - 1; i++)
            {
                if (x_intc[i] > x_intc[i + 1])
                {
                    int temp = x_intc[i];
                    x_intc[i] = x_intc[i + 1];
                    x_intc[i + 1] = temp;
                }
            }
        }
		for(int i=0; i<k; i+=2) {
            setcolor(10);
            int x = rand()%10;
            setcolor(x);

			line(x_intc[i], sl, x_intc[i + 1], sl);
			delay(100);
		}
	}
}

int main() {

	int gd = DETECT, gm = 0;

	poly P;
	P.getPoly();
	initgraph(&gd, &gm, NULL);
	            setcolor(BROWN);
	P.drawPoly();
	P.getSlopes();
		            setcolor(CYAN);
	P.scan();
	delay(10000);
	closegraph();
}
