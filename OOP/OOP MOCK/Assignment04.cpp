#include<iostream>
#include<fstream>
using namespace std;

int main(){
  	
	string name, email;
	int roll_no;
	// fflush(stdin);
	cout << "Enter name : ";
	getline(cin,name);

	cout << "Enter roll number : ";
	cin >> roll_no;

	cout << "Enter email id : ";
	cin >> email;  

	cout << "\tOpening file for writing...\n";
	ofstream s("File.txt");
	s << "jhgfds";
	s.close();
	ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	
	fout << name << endl << roll_no << endl << email;

	cout << "\tClosing the file...\n";
    fout.close();

	ifstream fin("File.txt");

	cout << "\tOpening file for reading...\n";

	getline(fin,name);
	fin >> roll_no;
	fin >> email;

	cout << "-----------------------------------------------------------------------\n";
	cout << "No."<<"\t"<<"Name" <<"\t\t\t" << "Email\n";
	cout << "-----------------------------------------------------------------------\n";
	cout << roll_no<<"\t"<<name <<"\t" << email << endl;	
	cout << "-----------------------------------------------------------------------\n";

	cout << "\tClosing the file...\n";

    fin.close();
}