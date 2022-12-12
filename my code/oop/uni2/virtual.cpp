#include<iostream>
using namespace std;

class A
{
    public:
        int a;
};

class B : virtual public A 
{
    public:
        int b;
};

class C : virtual public A
{
    public:
        int c;
};

class D : public B, public C
{
    public:
        int s;
    
        void sum()
        {
            s = a + b + c;

            cout << "Sum : " << s << endl;
        }
};

int main(int argc, char const *argv[])
{
    D obj;

    obj.a = 1;
    obj.b = 2;
    obj.c = 3;
    

    obj.sum();
    return 0;
}
