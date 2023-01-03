#include<iostream>
using namespace std;

class Complex
{

    public:
    int real, img;

        Complex()
        {
            real = img = 0;
        }

        Complex operator + (Complex);
        Complex operator * (Complex);

        friend ostream& operator<< (ostream&,Complex);
        friend istream& operator>> (istream&,Complex&);
};

ostream& operator << (ostream & out , Complex c){
    out << c.real << "i" << c.img << endl;
    return out;
}
istream& operator >> (istream&in,Complex& C){
    in >> C.real >> C.img;
    return in;
}
Complex Complex::operator+(Complex num)
{
    Complex sum;

    sum.real = this->real + num.real;
    sum.img = this->img + num.img;

    return sum;
}

Complex Complex::operator*(Complex num)
{

    // (a+ib)(c+id) = ac + adi + bci + bd*i^2
    //              = (ac - bd) + i*(ad+bc)
    Complex product;

    product.real = this->real * num.real - this->img * num.img;
    product.img = this->real * num.img + this->img * num.real;

    return product;
}


int main() {

Complex c1, c2;
    char ch;
    Complex sum, prod;

    cout << "Store two complex numbers :\n";
    cout << "Number 1:\n";
    cin >> c1;
    cout << "Number 2:\n";
    cin >> c2;

    cout << "*****M E N U*****\n";
    cout << "+ : Add complex numbers\n";
    cout << "* : Multiply complex numbers\n";
    cout << "# : Exit\n\n";
    cout << "Enter your choice : ";
    cin >> ch;

    switch(ch){

        case '+':
            sum = c1 + c2;
            cout << sum << endl;
            break;

        case '*':
            prod = c1 * c2;
            cout << prod << endl;
            break;

        case '#':
            cout << " T E R M I N A T I N G\n\n";
            exit(0);

        default:
            cout << "INVALID CHOICE !!\n";
    }

    return 0;
}
