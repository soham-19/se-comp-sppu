#include <iostream>
#include <vector>
using namespace std;

class base
{
public:
    base(){cout << "def of base\n";};

    base(int b)
    {
        cout << "para base\n";
    }

    void msf(){
        cout<< "base\n";
    }
};
class child : public base
{
    public:
    child():base(){
        cout << "def of child\n";
    }
    child(int ch):base(ch){
        cout<<"para of child\n";
    }

    void msf(){
        cout<< "der\n";
        base::msf();
    }

};
int main()
{
    child ch(9) ;
    ch.msf();
    return 0;
}