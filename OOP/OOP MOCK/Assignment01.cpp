#include<iostream>
using namespace std;

class Complex{

    int real;
    int img;

    public:

    Complex(){

        real = img = 0;
    }

    Complex operator + (Complex num){
        Complex result;

        result.img = this->img + num.img;
        result.real = this->real + num.real;

        return result;
    }

    Complex operator * (Complex num){
        Complex result; 

        result.real = this->real * num.real - this->img * num.img;
        result.img = this->real * num.img + this->img * num.real;

        return result;
    }

    friend istream& operator>> (istream&, Complex&);
    friend ostream& operator<< (ostream&, Complex);
};

istream& operator >> (istream &in, Complex &obj){

    cout << "Enter real part\n-> ";
    in >> obj.real;

    cout << "Enter img part\n-> ";
    in >> obj.img;
    cout << "Complex number saved successfully!\n\n";
    return in;
}

ostream& operator << (ostream& out, Complex obj){
    out << "\n\t#  Complex Number is : ";
    if(obj.img < 0)
        out << obj.real << " - " << obj.img << "i\n";
    else
        out << obj.real << " + " << obj.img << "i\n\n";
    return out;
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