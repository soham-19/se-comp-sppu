#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class ScanLine
{
public:
	int x[20], y[20], p, k, n;
	float slope[20], xint[20];
	void getCoordinates(int);
	void drawPoly();
};
void ScanLine::getCoordinates(int a)
{
	n = a;
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << ",y" << i + 1 << " : ";
		cin >> x[i] >> y[i];
	}
	x[n] = x[0];
	y[n] = y[0];
}
void ScanLine::drawPoly()
{
	for (int i = 0; i < n; i++)

		line(x[i], y[i], x[i + 1], y[i + 1]);
}

class polygon : public ScanLine
{
public:
	polygon(int a)
	{
		this->getCoordinates(a);
		this->drawPoly();
	}
	void getSlopes();
	void fillPoly();
	void getXInt();
	void sortXInt();
};
void polygon::fillPoly()
{
	this->getSlopes();
	for (p = 0; p < 480; p++)
	{
		this->getXInt();
		this->sortXInt();
		for (int i = 0; i < k; i += 2)
		{
			line(xint[i], p, xint[i + 1], p);
			delay(15);
		}
	}
}
void polygon::getSlopes()
{
	float dx, dy;
	for (int i = 0; i < n; i++)
	{
		dy = y[i + 1] - y[i];
		dx = x[i + 1] - x[i];
		if (dy == 0)
			slope[i] = 1;
		else if (dx == 0)
			slope[i] = 0;
		else
			slope[i] = dx / dy;
	}
}
void polygon::getXInt()
{
	k = 0;
	for (int i = 0; i < n; i++)
	{
		if ((y[i] <= p && y[i + 1] > p) || (y[i] > p && y[i + 1] <= p))
		{
			xint[k++] = x[i] + slope[i] * (p - y[i]);
		}
	}
}
void polygon::sortXInt()
{
	for (int i = 0; i < k; i++)
	{
		int minPos = i;
		for (int j = i + 1; j < k; j++)
		{
			if (xint[j] < xint[minPos])
				minPos = j;
		}
		swap(xint[minPos], xint[i]);
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	setcolor(BLACK);
	
	polygon P(4);

		setcolor(YELLOW);
		P.fillPoly();

	delay(10000);
}
