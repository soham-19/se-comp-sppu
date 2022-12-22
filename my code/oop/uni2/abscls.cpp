#include <iostream>
using namespace std;

class A{
    int a;

    public:
    A(){
        cout<<"A\n";
    }
        A(int _a) {
            a = _a;
        }

        virtual void vfnx() = 0;
};

class B : public A {
    int b;

    public:
        B(int _b) {
            b = _b;
        }

        void vfnx(){
            cout << "pure vir\n";
            cout << this;
        }
};
int main () {

    
    B b(9);
    B b1(9);
    b.vfnx();
    b1.vfnx();
    // A ob(7);
    return 0;
}