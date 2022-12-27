// soham kulkarni


/*

Implement C++ program for expression conversion as infix to postfix and its
evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
Only &#39;+&#39;, &#39;-&#39;, &#39;*&#39; and &#39;/ &#39; operators are expected.

*/

#include<iostream>
using namespace std;

class stack{

    char s[100];
    int top;

    public:

        stack(){
            top = -1;
        }
        
        bool empty(){
            return top == -1;
        }

        void push(char x){
            s[++top] = x;
        }

        void pop(){
            top--;
        }

        char peek(){
            return s[top];
        }
};

bool is_operand(char i){
    return  ( (i >= '0' && i <= '9') || (i >= 'a' && i <= 'z') ||
                (i >= 'A' && i <= 'Z'));
}

bool is_operator( char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence( char ch){

    if (ch=='*' || ch=='/')     return 2;
    if (ch=='+' || ch=='-')     return 1;
    else                        return -1;
}

string infixToPostfix( stack &s, string infix){

    string postfix;

    for (int i=0; i<infix.length(); i++)
    {
        if ( is_operand(infix[i]))

            postfix += infix[i];

        else if (infix[i] == '(')

            s.push(infix[i]);

        else if (infix[i] == ')') {

            while( s.peek() != '(' && !s.empty() ) {

                postfix += s.peek();
                s.pop();
            }

            if(s.peek() == '(')
                s.pop();
        }

        else if (is_operator(infix[i])) {

            if(s.empty())
                s.push(infix[i]);

            else
            {
                if ( precedence(infix[i]) > precedence(s.peek())) {
                    s.push(infix[i]);
                }
                else {                              // if precedence(infix[i] <= precedence(s.peek()))

                    while( !s.empty() && precedence(infix[i]) <= precedence(s.peek())){     // dont miss and

                        postfix += s.peek();
                        s.pop();
                    }

                    s.push(infix[i]);
                    
                }
            }

        }
    }

    while(!s.empty()){
        postfix += s.peek();
        s.pop();
    }

    return postfix;
}
int main() {

    string postfix, infix;

    cout << "Enter Infix : ";
    cin >> infix;

    stack Stack;

    cout << "INFIX  : " << infix << endl;

    postfix = infixToPostfix(Stack, infix);

    cout << "POSTFIX  : " << postfix << endl;

    return 0;
}       

// hard testcase
// infix : A+7-(I*U(O-A)/n)+8*P
// postfix : A7+IUOA-*n/-8P*+


// Enter Infix : a+b*(c-d)/e
// INFIX  : a+b*(c-d)/e
// POSTFIX  : abcd-*+e/