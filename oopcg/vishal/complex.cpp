//problem statement
//Implement the class complex the complex no. data type.Implement the following i.constructor ii.overload operator '+' to add two complex no.
//iii.Overload operator '*' to multiply two complex no. iv.Overload operator insertion and extraction.
#include<iostream>
#include<string>
using namespace std;


class complex
{
	public:
	int real,img;
};

int main()
{
	complex a,b,c,d;
	cout<<"Enter the first complex number :";
	cout<<"\na = ";
	cin>>a.real;
	cout<<"b = ";
	cin>>a.img;
   	cout<<"Enter the second complex number is :";
  	cout<<"\nc = ";
	cin>>b.real;
  	cout<<"d = ";
	cin>>b.img;
   
	c.real = a.real + b.real;
	c.img = a.img + b.img;
	
	d.real = a.real * b.real;
	d.img = a.img * b.img;
	
	cout<<"Sum of two complex numbers = "<<c.real<<" + "<<c.img<<"i"<<endl;
	cout<<"Multiplication of two complex numbers = "<<d.real<<" * "<<d.img<<"i";
	
	return 0;
}












	/*if (c.img >= 0)
	cout << "Sum of two complex numbers = " << c.real << " + " << c.img << "i";
	else
	cout << "Sum of two complex numbers = " << c.real << " " << c.img << "i";
	*/

