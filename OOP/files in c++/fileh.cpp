#include <iostream>
#include <fstream>
using namespace std;


/*
fstreambase
ifstream
ofstream

in order to work with files in cpp
firstly open it 
*/
int main () {
    string soh ;
    // ofstream out("sample.txt");
    // out << soh;

    ifstream in("sample.txt");
    getline(in,soh);
    getline(in,soh);

    cout << soh;
    return 0;
}