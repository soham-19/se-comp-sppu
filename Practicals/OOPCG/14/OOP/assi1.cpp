
#include<iostream>
using namespace std;

class student
{
	/*private:
	int roll_no;
	char name[20];
	char Class[5];
	char Div;
	char DOB[20];
	char Drivinglicenseno[30];
	char Bloodgroup[5];
	long int mobileno;
	static int count;
	friend void display(student &obj);*/


	public:
	int roll_no;
	char name[20];
	char Class[5];
	char Div;
	char DOB[20];
	//char Drivinglicenseno[30];
	char Bloodgroup[5];
	long int mobileno;
	static int count;
	void getdata();
	friend void display(student &obj);
	
	student()		//constructor
	{	
		roll_no=0;	
		cout<<"\nConstructor";
		roll_no=count;
		count++;
	}
	
	student(int roll_no)	//parameterised constructor
	{
		this->roll_no=roll_no;
	}

	~student()
	{
		cout<<"\nDestructor";	//destructor

	count++;
	}	

};	//end of class

int student::count=0;

void student::getdata()
{
	cout<<"\n Enter roll no:";
	cin>>roll_no;

	cout<<"\n Enter name:";
	cin>>name;

	cout<<"\n Enter Class:";
	cin>>Class;

	cout<<"\n Enter Div:";
	cin>>Div;
	cout<<"\n Enter Date of birth:";
	cin>>DOB;

	//cout<<"\n Enter Driving license no:";
	//cin>>Drivinglicenseno;

	cout<<"\n Blood group:";
	cin>>Bloodgroup;

	cout<<"\nEnter mobile no:";
	cin>>mobileno; 	
}

void display(student &obj)
{	
	/*cout<<"\nRoll No:"<<obj.roll_no;
	cout<<"\nName:"<<obj.name;

	cout<<"\nClass:"<<obj.Class;

	cout<<"\nDiv:"<<obj.Div;

	cout<<"\nDOB:"<<obj.DOB;

	//cout<<"\nDrivinglicenseno:"<<obj.Drivinglicenseno;

	cout<<"\nBloodgroup:"<<obj.Bloodgroup;

	cout<<"\nmobileno:"<<obj.mobileno;*/
	cout<<"\n"<<obj.roll_no;
	cout<<"\t"<<obj.name;
	cout<<"\t"<<obj.Class;
	cout<<"\t"<<obj.Div;
	cout<<"\t"<<obj.DOB;
	cout<<"\t\t"<<obj.Bloodgroup;
	cout<<"\t"<<obj.mobileno;
}

int main()
{
	student s1,s2,s3;
	cout<<"\nEnter data for first student";
	s1.getdata();
	//cout<<"\nEnter data for second student";
	//s2.getdata();
	//cout<<"\nEnter data for third student";
	//s3.getdata();
	cout<<"\nAll details are given below";
	cout<<"\nRoll No\tName\tClass\tDiv\tDate of birth\tBlood group\tMobile no";
	display(s1);	
	//display(s2);
	//display(s3);

return 0;
}



