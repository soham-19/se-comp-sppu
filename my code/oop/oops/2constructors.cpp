#include <iostream>
using namespace std;

class person{
    int age;

    public:

    person (int a=0)
        {age = a;}

    void p()
        {cout<<"age "<<age<<endl;}
};

int main () {

    person soh(19);
    soh.p();

    return 0;
}