#include <iostream>
using namespace std;

class Complex{
    private:
        int real;
        int img;

    public:

        Complex (){
            this->real = 0;
            this->img = 0;
        }

        Complex(int x, int y){
            this->real = x;
            this->img = y;
        }

        void printNum();

        Complex operator+ ( Complex &obj){
            Complex tempObj;

            tempObj.img = this->img + obj.img;
            tempObj.real = this->real + obj.real;

            return tempObj;
        }

        Complex operator* (Complex &obj){

            // (a+ib)*(c+id) = ac + adi + bci + i^2bd = ac - bd + (ad+bc)i
            Complex tempObj;

            tempObj.real = this->real * obj.real - this->img * obj.img;

            tempObj.img = this->real * obj.img + this->img * obj.real;

            return tempObj;
        }

        friend ostream& operator << (ostream &out, Complex &obj);
        friend istream& operator >> (istream &in, Complex &obj);
};

ostream& operator<< (ostream &out, Complex &obj){

        if(obj.img<0)
            out << obj.real << "-" << -1*obj.img << "i" << endl;
        else
            out << obj.real << "+" << obj.img << "i" << endl;

        return out;
}

istream& operator>>(istream &inp, Complex &obj){
    cout<<"  =>Real part :  ";
    inp>>obj.real;
    cout<<"  =>Img part :  ";
    inp>>obj.img;
    cout << endl;

    return inp;
}

// DRIVER CODE 

int main () {

    Complex c1, c2, c_add, c_product;

    cout << "Enter 1st complex number"<<endl;
    cin>>c1;

    cout << "Enter 1st complex number"<<endl;
    cin>>c2;

    c_add = c1 + c2;

    cout << "Addition is : "<<endl;
    cout<<c_add;

    c_product = c1 * c2;

    cout << "\nProduct is : "<<endl;
    cout << c_product;   

    return 0;
}