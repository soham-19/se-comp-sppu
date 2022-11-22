#include<iostream>
using namespace std;

class house {
    int len;
    int bre;

    public:

    void setData( int l, int b ) {
        len = l;
        bre = b;
    }

    void area() {
        cout << "area = " <<len*bre<<endl;
    }
};

int main () {
    house h1;
    h1.setData(300,500);
    h1.area();
}