/*
    Develop a program in C++ to create a database of
    student’s information system containing the following
    information: Name, Roll number, Class, Division,
    Date of Birth, Blood group, Contact address,
    Telephone number, Driving license no. and other.
    Construct the database with suitable member
    functions. Make use of constructor, default
    constructor, copy constructor, destructor, static
    member functions, friend class, this pointer, inline
    code and dynamic memory allocation operators-new
    and delete as well as exception handling.
*/
#include<iostream>
using namespace std;

class Student{
        int roll_no;
        string name;
        string std;
        char div;
        string dob;
        string blood_grp;
        string phn_no;
        string addr;
        static int count;
    public:

        void getData();

        static void getCount();

        friend void printData(Student);


        // default const.

        Student(){
            roll_no = 0;
            cout << "Constructor\t";
            count++;
        }

        // copy const
        Student(Student & obj){
            roll_no = obj.roll_no;
            name = obj.name;
            std = obj.std;
            div = obj.div;
            dob = obj.dob;
            blood_grp = obj.blood_grp;
            phn_no = obj.phn_no;
            addr = obj.addr;
            count++;
        }

        ~Student(){
            cout << "Destroying the object...\n";
            count--;
        }

};
int Student::count = 0;

void Student::getData(){
    cout << "Enter Roll No. : ";
    cin >> roll_no;

    cout << "Enter name : ";
    fflush(stdin);
    getline(cin,name);

    cout << "Enter standard : ";
    fflush(stdin);
    getline(cin,std);

    cout << "Enter div : ";
    fflush(stdin);
    div = getchar();

    cout << "Enter DOB : ";
    fflush(stdin);
    getline(cin,dob);

    cout << "Enter blood group : ";
    fflush(stdin);
    getline(cin,blood_grp);

    cout << "Enter Phone Number : ";
    fflush(stdin);
    getline(cin,phn_no);

    cout << "Enter Address : ";
    fflush(stdin);
    getline(cin,addr);
}

void printData(Student obj){
    cout << "\n"
         << obj.roll_no
         << "\t"
         << obj.name
         << "\t" << obj.std << "\t" << obj.div
         << "\t"
         << obj.dob
         << "\t" << obj.phn_no
         << "\t" << obj.blood_grp << "\t";
}

void Student::getCount(){
    cout << "Count : " << count << endl;
}


int main(int argc, char const *argv[])
{
    Student s1;
    s1.getData();
    printData(s1);
    
    return 0;
}

/*

Implement C++ program for expression conversion as infix to postfix and its
evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
Only &#39;+&#39;, &#39;-&#39;, &#39;*&#39; and &#39;/ &#39; operators are expected.


#include<iostream>
// #include<stack>
using namespace std;
#define N 100
class stack{

    char s[N];

    public:
    int top;

        stack(){
            top = -1;
        }

        void push(char);
        void pop();
        char peek();

        bool isempty();

};

bool stack::isempty(){
    return top == -1;
}
void stack::push(char ch){
    if(top+1 == N){
        cout << "Stack Full\n";
        return;
    }

    s[++top] = ch;
}

char stack::peek(){
    if (isempty()){
        cout << "Stack Empty\n";
        return '!';
    }

    return s[top];
}

void stack::pop(){
    if (isempty()){
        cout << "Stack Empty\n";
        return;   
    }

    top--;
}

int precedence(char ch){

    if( ch=='^')    return 3;

    if( ch=='*' || ch == '/')    return 2;

    if( ch=='+' || ch == '-')    return 1;
    
}
bool isOperand( char ch) {

    return( (ch >= 'a' && ch <= 'z') || (ch>='A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

bool isOperator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
string infixToPostfix(stack &Stack, string infix) {

    string postfix;

    for( int i=0; i<infix.length(); i++){

        if(isOperand(infix[i]))
            
            postfix += infix[i];

        else if(infix[i] == '(') 
            
            Stack.push(infix.at(i));

        else if(infix[i] == ')'){

            while( !Stack.isempty() && Stack.peek()!= '('){

                postfix += Stack.peek();
                Stack.pop();
            }

            if(Stack.peek() == '('){
                Stack.pop();
            }
        }

        else if(isOperator(infix[i])) {

            if(Stack.isempty()) 
                Stack.push(infix[i]);
            
            else {

                if(precedence(infix[i]) > precedence(infix[Stack.top]))
                    Stack.push(infix[i]);

                else if (precedence(infix[i]) == precedence(infix[Stack.top]) && infix[i] == '^')
                    Stack.push(infix[i]);

                else{

                    while(!Stack.isempty() && precedence(infix[i]) <= precedence(infix[Stack.top])) {
                        
                        postfix += Stack.peek();
                        Stack.pop();
                    }

                    Stack.push(infix[i]);
                }


            }
        }

        else{
            cout << "Invalid symbol detected : " << infix[i]<<endl;
            cout << "Exiting ...\n";
            exit(1);
        }
    }

    while(!Stack.isempty()){
        postfix += Stack.peek();
        Stack.pop();
    }

    return postfix;
}

int main() {

    string postfix, infix;

    cout << "Enter an Infix Expression : ";
    cin >> infix;

    stack ExpStack;

    cout << "INFIX EXPRESSION : " << infix << endl;

    postfix = infixToPostfix(ExpStack, infix);

    cout << "POSTFIX EXPRESSION : " << postfix << endl;
}
*/
