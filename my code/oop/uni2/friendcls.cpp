#include<iostream>
using namespace std;

class MyClass1
{

    private:
    int x;

    public:

    friend class myClass2;
        MyClass1(int a){x=a;}
};


class myClass2
{
    public:

    void show(MyClass1 obj)
    {
        cout << "x is "<<obj.x<<endl;
    }
};


int main(){

    MyClass1 obj1(5);

    myClass2 obj2;

    obj2.show(obj1);

    return 0;
}