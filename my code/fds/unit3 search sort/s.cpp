#include <iostream>
#include <vector>
using namespace std;

int main () {

    char s[] = "soham";
    int count = 0;
    for (int i=0; s[i]!='\0'; i++)
        count++;
    cout << count;
    return 0;
}