#include<iostream>
using namespace std;

class DLL{
    
    bool bit;
    DLL * next, * prev;

    public:

        static DLL * start, * end;

        DLL(){
            cout << "==> bit : ";
            cin >> bit;
            next = prev = NULL;

            if(start == NULL){
                start = end = this;
            }
            else{
                end->next = this;
                this->prev = end;
                end = end->next;
            }
        }

        void display(){
            DLL * ptr = start;

            while(ptr != NULL){
                cout << ptr->bit;
                ptr = ptr->next;
            }
            cout << endl;
        }

        void onecomp(){
            DLL * ptr = start;

            while(ptr != NULL){
                cout << !ptr->bit;
                ptr = ptr->next;
            }
            cout << endl;
        }
};

DLL *DLL::end = NULL;
DLL *DLL::start = NULL;

int main(){

    DLL * obj;


    while(1){
            
    cout << "MENU\n";
    cout << "1-Add bit\n";
    cout << "2-Display\n";
    cout << "4-Display 1's cpmp\n";
    cout << ".-Exit\n";
    cout << "Enter your choice.\n==>";

    char ch;

    cin >> ch;

    switch(ch){

        case '1':
            obj = new DLL;
            break;
        case '2':
            obj->display();
            break;
        case '4':
            obj->onecomp();
            break;
        case '.':
            exit(0);

    }
    }
}