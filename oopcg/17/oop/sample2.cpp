#include<iostream>
#include<bits/stdc++.h>
#define max_len 25
using namespace std;


class student
{

	char name[max_len];
	int roll_no;
	char Class[3];
	char div[3];
	char dob[15];
	char blood_group[3];
	signed char contact[11];
	char address[20];
	signed char tel_no[12];
	char license_no[15];
public:
	void getdata();
	void display();
	
};

void student::getdata()
{
	cout<<"\nEnter Name ";
	cin>>name;
	cout<<"\nEnter Roll number  ";
	cin>>roll_no;
	cout<<"\nEnter Class ";
	cin>>Class;
	cout<<"\nEnter Division ";
	cin>>div;
	cout<<"\nEnter Date of Birth in dd-mm-yyyy ";
	cin>>dob;
	cout<<"\nEnter Blood group ";
	cin>>blood_group;
	cout<<"\nEnter Contact no ";
	cin>>contact;
	cout<<"\nEnter Address ";
	cin>>address;
	cout<<"\nEnter Telephone no ";
	cin>>tel_no;
	cout<<"\nEnter Driving license no ";
	cin>>license_no;
}

void student::display()
{
	cout<<"\nName : "<<name;
	cout<<"\nRoll no: "<<roll_no;
	cout<<"\nClass : "<<Class;
	cout<<"\nDivision :  "<<div;
	cout<<"\nDate of Birth : "<<dob;
	cout<<"\nBlood group: "<<blood_group;
	cout<<"\nContact no :"<<contact;
	cout<<"\nAddress : "<<address;
	cout<<"\nTelephone no : "<<tel_no;
	cout<<"\nDriving license no : "<<license_no;
}

int main()
{
	student s1;
	s1.getdata();
	
	student s2;
	s2.getdata();
	
	student s3;
	s3.getdata();

	student s4;
	s4.getdata();
	
	student s5;
	s5.getdata();
	
	s1.display();
	s2.display();
	s3.display();
	s4.display();
	s5.display();
	return 0;
}
	
