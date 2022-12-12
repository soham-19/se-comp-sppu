#include <iostream>

class A
{
public:
    int _a = 3;
    void method(){std::cout << "A\n";};
};
class B : public A
{
public:

    int _b = 7;
    void method(){std::cout << "B\n";};
};
class C : public A
{
public:
    int _c = 9;
    void method(){std::cout << "C\n";};
};
class D : public B, public C
{
public:
    int _d;
    // void method(){std::cout << "D\n";};
};
using namespace std;

int main()
{   
        D d;
        // d.method();
        d._d = 2;
        std::cout << d._a;

    return 0;
}