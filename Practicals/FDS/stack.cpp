#include<iostream>
using namespace std;
#define M 5
class Stack
{
    int stk[M], top;

    public:

    Stack(){
        top = -1;
    }

    bool isFull();
    bool isEmpty();
    int getTop();
    void push(int);
    void pop();
    void display();
};

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull(){
    return top == M-1;
}

int Stack::getTop(){
    return stk[top];
}

void Stack::push(int x){
    if(isFull()){
        cout << "Overflow\n";
        return;
    }
    else
        stk[++top] = x;
}

void Stack::pop(){
    top--;
}

void Stack::display(){
    if(isEmpty()) {
        cout << "EMPTY\n";
        return;
    }
    else{

        cout << "Stack is : ";
        for(int i=top;i>=0;i--)
            cout << stk[i] << " ";

        cout << endl;
    }
}
int getData(){

    cout << "   ==>Enter data  ";
    int x;
    cin >> x;
    cout << endl;
    return x;
}
int main () {

    int x, ch;
    Stack s;

    while(true){
        cout << endl
             << "    STACK OPERATIONS    " << endl
             << endl
             << "1-push" << endl
             << "2-pop" << endl
             << "3-getTop" << endl
             << "4-Display" << endl
             << "0-Exit" << endl;
        cout << " ==>your choice ";
        cin >> ch;
        cout << endl;

        switch(ch){
            case 1:
                x = getData();
                s.push(x);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top->"<<s.getTop();
                break;
            case 4:
                s.display();
                break;
            case 0:
                cout << ". . . . . Terminating . . . . ." << endl;
                exit(0);
            default:
                cout << "Invalid choice";
                break;
        }
    }
    return 0;
}
