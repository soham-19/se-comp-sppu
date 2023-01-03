#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    string name, email;
    int roll;

    cout << "Enter roll no. : ";
    cin >> roll;
    getline(cin,name);
    cout << "Enter name : ";
    getline(cin,name);
    cout << "Enter email-id : ";
    cin >> email;

    cout << "\n\t#Opening file for writing....\n";

    ofstream fout("FINAL.txt");

    fout << name << endl;
    fout << roll << endl;
    fout << email << endl;

    cout << "\n\t#Closing file....\n";

    fout.close();

    cout << "\n\t#Opening file for reading....\n";

    ifstream fin("FINAL.txt");

    getline(fin,name);
    fin >> roll;
    fin >> email;
    cout << "\n\t#Closing file....\n";
    fin.close();
    
    cout << "No.\tName\t\tEmail\n";
    cout << "--------------------------------------------------------------\n";
    cout << roll << "\t" << name << "\t\t" << email << endl;
    cout << "--------------------------------------------------------------\n";
}