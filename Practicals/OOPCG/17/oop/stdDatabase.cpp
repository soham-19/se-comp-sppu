#include <iostream>
using namespace std;
class student
{
private:
	int roll_no;
	char name[20];
	char standard[5];
	char div;
	char DOB[20];
	char bloodgrp[10];
	long int mobileno;
	char drivinglicenceno[20];
	char address[30];
public:
	void getdata();
	void display();
};
void student::getdata()
{
	cout<<"\n Enter roll_no:";
	cin>>roll_no;
	cout<<"\n Enter name:";
	cin>>name;
	cout<<"\n Enter standard:";
	cin>>standard;
	cout<<"\n Enter div:";
	cin>>div;
	cout<<"\n Enter DOB:";
	cin>>DOB;
	cout<<"\n Enter bloodgrp:";
	cin>>bloodgrp;
	cout<<"\n Enter mobileno:";
	cin>>mobileno;
	cout<<"\n Enter drivinglicenceno:";
	cin>>drivinglicenceno;
	cout<<"\n Enter address:";
	cin>>address; 
}
void student::display()
{
	cout<<roll_no<<"\n";
	cout<<name<<"\n";
	cout<<standard<<"\n";
	cout<<div<<"\n";
	cout<<DOB<<"\n";
	cout<<bloodgrp<<"\n";
	cout<<mobileno<<"\n";
	cout<<drivinglicenceno<<"\n";
	cout<<address<<"\n";                         
}
int main()
{
	student s;
	s.getdata();
	s.display();
	return 0;
}




	
