/*
Write a C++ program that creates an output file, writes
information to it, closes the file, open it again as an
input file and read the information from the file.
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){

    string name;
    int roll;
    string email;

    cout << "Enter name : ";
    getline(cin,name);
    cout << "Enter roll number : ";
    cin >> roll;
    cout << "Enter email-id : ";
    cin >> email;

    ofstream fout ("Student data.txt"); // opening file by const.

    cout << "\tfile opened for writing...\n";

    fout << name << endl;
    fout << roll << endl;
    fout << email;
    
    cout << "\tfile is being closed...\n";

    fout.close();

    ifstream fin ("Student data.text");
    cout << "\tfile opened for reading...\n";

    getline(fin, name);
    fin >> roll;
    getline(fin, email);

    cout << "Name : " << name << "\t" << "Roll No : " << roll << "\t" << "Email : " << email << endl;
    
    cout << "\tfile is being closed...\n";

    fout.close();

}