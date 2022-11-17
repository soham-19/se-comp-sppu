/*Implement the complex class representing thye complex number datatype. Implkement the following:
1.Default constructor which creates the complex no 0+0i
2.Overload operator "+" to add two complex numbers
3.Overload operator "*" to multiply two complex numbers 
4.Overload operator - Insertion and Extraction operators to print and read complex nos.
*/

#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
	public:
		int real, imag;
	Complex()
		{
			real=imag=0;
		}
	Complex(int r, int i)
		{
			real=r;
			imag=i; 
		}
	friend istream &operator>>(istream &input , Complex &c)
	{
		input>>c.real>>c.imag;
		return input;
		
	}
	
	friend ostream &operator<<(ostream &output , Complex &c)
	{
		output<<c.real<<"i"<<c.imag;
		return output;
		
	}
	
	Complex operator +(Complex c2)
	{
		Complex c3;
		c3.real=real+c2.real;
		c3.imag=imag+c2.imag;
		return c3;
	}
	
	Complex operator *(Complex c2)
	{
		Complex c3;
		c3.real=(real*c2.real) - (imag*c2.imag); //(ac-bd)
		c3.imag=(real*c2.imag) + (imag*c2.real); //(ad+bc)i
		return c3;
	}
	
	void display()
	{
		if(imag>=0)
		{
			cout<<"\n"<<real<<"+"<<imag<<"i";
		}
		else
		{
			cout<<"\n"<<real<<"-"<<abs(imag)<<"i";
		}
	}
		
};

int main()
{
	int choice,Y;
	Complex c,c1,c2,c3;
	cout<<"\nDefault complex number is: ";
	c.display();
	
	do
	{
	cout<<"\nEnter 1st complex number:";
	cin>>c1;
	c1.display();
	cout<<"\nEnter 2nd complex number:";
	cin>>c2;
	c2.display();
	cout<<"\nEnter your choice:";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\nAddition is:";
			c3=c1+c2;
			c3.display();
		break;
		
		case 2:
			cout<<"\nMultiplication is:";
			c3=c1*c2;
			c3.display();
		break;
	}
	cout<<"\nIf you want to continue then press 1:";
	cin>>Y;
	}
	while(Y==1);
	return 0;
	
}


/*OUTPUT:
Default complex number is: 
0+0i
Enter 1st complex number:2
-1

2-1i
Enter 2nd complex number:2
1

2+1i
Enter your choice:2

Multiplication is:
5+0i
*/



