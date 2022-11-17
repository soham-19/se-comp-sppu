#include<iostream>
#include<string.h>
using namespace std;

class student
{
	public:
	int srno;
	char name[30];
	int rollno;
	char cls[5];
	char div[5];
	char dob[15];
	char bldgrp[7];
	char add[50];
	unsigned long int mobno;
	char dlno[25];
	static int count;
	void get_data();
	friend void display_data(student & obj);

	student()
	{
		rollno=0;
		cout<<"/t Constructor";
		rollno=count;
		count++;
	}

	~student()
	{
		cout<<"/t Destructor";
		cout<<"Destroying the object";
		count++;
	}

	static void getcount()
	{
		cout<<"\n Count"<<count;
	}

	student (int rollno)
	{
		this-> rollno=rollno;
	}

	student (student & obj)
	{
		strcpy(name,obj.name);
		rollno=obj.rollno;
		strcpy(cls,obj.cls);
		strcpy(div,obj.div);
		strcpy(dob,obj.dob);
		strcpy(bldgrp,obj.bldgrp);
		strcpy(add,obj.add);
		mobno=obj.mobno;
		strcpy(dlno,obj.dlno);
		srno=count;
		count++;
	}
};

int student::count=0;
void student::get_data()
{
	cout<<"\nEnter Student Name:";
	cin>>name;
	cout<<"\nEnter Roll No:";
	cin>>rollno;
	cout<<"\nEnter Class:";
	cin>>cls;
	cout<<"\nEnter Division:";
	cin>>div;
	cout<<"\nEnter Date of Birth:";
	cin>>dob;
	cout<<"\nEnter Blood Group:";
	cin>>bldgrp;
	cout<<"\nEnter Address:";
	cin>>add;
	cout<<"\nEnter Mobile No:";
	cin>>mobno;
	cout<<"\nEnter Driving License No:";
	cin>>dlno;
}

void display_data(student & obj)
{
	cout<<"\t"<<obj.name;
	cout<<"\t"<<obj.rollno;
	cout<<"\t"<<obj.cls;
	cout<<"\t"<<obj.div;
	cout<<"\t"<<obj.dob;
	cout<<"\t"<<obj.bldgrp;
	cout<<"\t"<<obj.add;
	cout<<"\t"<<obj.mobno;
	cout<<"\t"<<obj.dlno;
}

int main()
{
	student s1;
	student s2(s1);   //copy constructor
	cout<<"\nEnter data for 1st student:"<<"\n";
	s1.get_data();
	
	cout<<"All the details are given below:";
	cout<<"\n Sr.No. \t Roll No. \t Name \t Class \t Div \t DOB \t Blood Group \t Address \t Mobile No. \t DL No.\n";
	display_data(s1);
	
	student *s[50];  //array of objects
	int i,n;
	cout<<"\nHow many student objects you want to create?";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		s[i]=new student();
	}
	
	for(i=0;i<n;i++)
	{
		s[i]->get_data();
	}
	
	for(i=0;i<n;i++)
	{
		display_data(*s[i]);
	}
	
	for(i=0;i<n;i++)
	{
		delete (s[i]);
	}
	return 0;
}

/*
OUTPUT:-
Enter Student Name:XYZ

Enter Roll No:35

Enter Class:SE

Enter Division:B

Enter Date of Birth:4/1/2004

Enter Blood Group:A+

Enter Address:Nashik

Enter Mobile No:9878684579

Enter Driving License No:9506776hgnh
All the details are given below:
 Sr.No. 	 Roll No. 	 Name 	 Class 	 Div 	 DOB 	 Blood Group 	 Address 	 Mobile No. 	 DL No.
	XYZ	35	SE	B	4/1/2004	A+	Nashik	9878684579	9506776hgnh
*/	

