#include <graphics.h>
#include <math.h>
#include <iostream>

const double PI = 3.14159265358979323846;

class Ball {
public:
    virtual void draw(int x, int y) = 0;
    virtual void erase(int x, int y) = 0;
};

class SinBall : public Ball {
private:
    int radius;
    int color;

public:
    SinBall(int r, int c) : radius(r), color(c) {}

    void draw(int x, int y) {
        setcolor(color);
        circle(x, y, radius);
        floodfill(x, y, color);
    }

    void erase(int x, int y) {
        setcolor(BLACK);
        circle(x, y, radius);
        floodfill(x, y, BLACK);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Ball *ball = new SinBall(10, WHITE);
    int x = 10, y = 100;
    int dx = 1, dy = 1;
    double t = 0;
    double dt = 0.1;

    while (true) {
        ball->erase(x, y);
        t += dt;
        x = x + dx;
        y = 100 + 50 * sin(t);
        ball->draw(x, y);
        cleardevice();
        delay(10);
    }

    closegraph();
    return 0;
}

