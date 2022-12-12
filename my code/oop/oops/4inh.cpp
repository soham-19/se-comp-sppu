#include <iostream>
#include <vector>
using namespace std;

class Rectangle{
    public:

    int l,b;

    void area(){
        cout << "area "<<l*b<<endl;
    }
};

class cuboid : public Rectangle{
    public:
    int h;

    void vol(){
        cout << "vol " << l*b*h<<endl;
    }
};
int main () {

    cuboid c;
    c.l = 10;
    c.b = 8, c.h = 5;
    c.vol();
    c.area();
    

    return 0;
}