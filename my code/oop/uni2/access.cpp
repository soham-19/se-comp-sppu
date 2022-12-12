#include <iostream>
using namespace std;

class base
{
    protected:
    int x;

public:
    void setX(int n) { x = n; }
    void showX() { cout << "X : " << x << endl; }
};

class derived : protected base
{
    int y;

public:
    void setY(int n) { y = n; }
    void showXY()
    {
        // cout << "X : " << x << endl;
        this->showX();
        cout << "Y : " << y << endl;
    }
};

main()
{

    derived o;

    // o.setX(5);
    o.setY(6);
    // o.showX();
    o.showXY();
}