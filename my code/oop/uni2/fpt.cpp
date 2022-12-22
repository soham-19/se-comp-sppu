#include <iostream>
#include <vector>
using namespace std;

    int add(int a,int b){
        return a+b;
    }
int main () {


    int (*p)  (int,int);

    p = &add;

    cout << (*p)(2,3);
    return 0;
}