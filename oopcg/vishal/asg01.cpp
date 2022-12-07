#include<iostream>
using namespace std;

class Student {

	int rollNo;
	char name[25];
	char cls[3];
	char div;
	char dob[12];
	char bloodGrp [3];
	long int mobNo;
	char drvLinNo[10];
	
	public:
	void getData();
	void displayData();
};

void Student::getData() {

	cout << "Enter roll number." << endl;
	cin >> rollNo;
	cout << "Enter name." << endl;
	cin >> name;
	
	cout << "Enter class." << endl;
	cin >> cls;
	
	cout << "Enter division." << endl;
	cin >> div;
	
	cout << "Enter date of birth." << endl;
	cin >> dob;
	
	cout << "Enter blood group" << endl;
	cin >> bloodGrp;
	
	cout << "Enter mobile number." << endl;
	cin >> mobNo;
	
	cout << "Enter driving license number." << endl;
	cin >> drvLinNo;
}

void Student::displayData() {

	cout << "Roll No. :\t";
	cout << rollNo << endl;
	
	cout << "Student Name:\t";
	cout << name << endl;
	
	cout << "Class :\t\t";
	cout << cls << endl;
	
	cout << "Division :\t";
	cout << div << endl;
	
	cout << "Date of birth : ";
	cout << dob << endl;
	
	cout << "Blood Group : \t";
	cout << bloodGrp << endl;
	
	cout << "Mobile Number :\t";
	cout << mobNo << endl;

	cout << "Driving License Number : ";
	cout << drvLinNo << endl;

}

int main () {

	
	Student arr[10];
	for ( int i=0; i<10; i++ ) {
		cout << "Enter details of " << i+1 << "th student :\n";
		arr[i].getData();
	}
	
	for ( int i=0; i<10; i++ ) {
		cout << "Details of " << i+1 << "th student :\n";
		arr[i].displayData();
	}
	return 0;
}
