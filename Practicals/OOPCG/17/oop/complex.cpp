#include<iostream>
using namespace std;
class complex
{
public:
int r1,r2,i1,i2;
void getdata();
void display();
int multiply();
int pdt();

complex()
{
	r1=0;
	r2=0;
	i1=0;
	i2=0;}
};
void complex::getdata()
{
	cout<<"Enter the 1st complex no.";
	cin>>r1>>i1;
	cout<<"Enter the 2nd complex no.";
	cin>>r2>>i2;
}
void complex::display()
{
	cout<<"\n"<<r1<<"+i"<<i1;
	cout<<"\n"<<r2<<"+i"<<i2;
}
int complex::multiply()
{
	int c1,c2;
	c1=r1*r2;
	c2=i1*i2;
	cout<<"\n multiplication is"<<c1<<"+i"<<c2;
	return 0;
}
int main()
{
	complex obj;
	obj.getdata();
	obj.display();
	obj.multiply();
	return 0;
}




