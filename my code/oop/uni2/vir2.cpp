#include<iostream>
using namespace std;

class A
{
    public:

    virtual void hi(){
        cout<<"hi base\n";
    }


};

class B : public A
{
    public:

    void hi(){
        cout<<"hi der\n";
    }


};

int main()
{

    A * p ;
    B b;
    p = &b;

    p->hi();
    return 0;
}
