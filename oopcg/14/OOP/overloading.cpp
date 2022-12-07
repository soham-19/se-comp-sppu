class complex
{
private:
float real;
float img;
public:
        complex()                //default constructor
        {
         real=0;
         img=0;
        }
friend  istream &operator>>(istream &in,complex &c);
friend  ostream &operator<<(ostream &out,complex &c);
complex operator+(complex t);
complex operator*(complex t);
};

istream &operator>>(istream&in,complex&c)
{
      cout<<"\nEnter real and imaginary parts of number:";
      in>>c.real>>c.img;
      return in;
}
   
ostream &operator<<(ostream&out,complex&c)
{  
cout<<"\nThe complex no is:";
        out<<c.real<<"+"<<c.img<<"i";
        return out;
}

complex complex::operator+(complex t)
{
complex temp;
temp.real=real + t.real;
temp.img=img + t.img;
return temp;
}
complex complex::operator*(complex t)
{
complex temp;
temp.real=(real*t.real)-(img*t.img);
temp.img=(real*t.img)+(t.real*img);
return temp;
}

int main()
{
complex c1,c2,c3;
cout<<"\n Default Complex numbers \n C1:"<<c1<<"\n C2:"<<c2;
cout<<"\nFOR 1ST COMPLEX NO";
    cin>>c1;
      cout<<c1;
     
cout<<"\nFOR 2ND COMPLEX NO";
cin>>c2;
    cout<<c2;

int choice;

cout<<"\nENTER THE OPERATION WHICH IS TO BE PERFORMED:\n1.ADDITION \n2.MULTIPLICATION ";
cin>>choice;

switch(choice)
{
case 1:cout<<"\n PERFORMING ADDITION";
c3=c1+c2;
cout<<c3;
break;
case 2:cout<<"\n PERFORMING MULTIPLICATION";
c3=c1*c2;
cout<<c3;
break;

default: cout<<"INVALID CHOICE";
}
     
return 0;
}
