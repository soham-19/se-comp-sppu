/*
Implement C++ program for expression conversion as infix to postfix and its
evaluation using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
Only &#39;+&#39;, &#39;-&#39;, &#39;*&#39; and &#39;/ &#39; operators are expected.
*/

#include<iostream>
#include<stack>
using namespace std;

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
string infixToPostfix(stack<char> Stack, string infix) {

    string postfix;

    for( int i=0; i<infix.length(); i++){

        if(isOperand(infix[i]))
            
            postfix += infix[i];

        else if(infix[i] == '(') 
            
            Stack.push(infix.at(i));

        else if(infix[i] == ')'){

            while( !Stack.empty() && Stack.top()!= '('){

                postfix += Stack.top();
                Stack.pop();
            }
        }

        else if(isOperator(infix[i])) {

            if(Stack.empty()) {
                Stack.push(infix[i]);
            }
            else {
                int p = precedence(infix[i]);
            }
        }

        else{
            cout << "Invalid symbol detected : " << infix[i]<<endl;
            cout << "Exiting ...\n";
            exit(1);
        }
    }

    return postfix;
}

int main() {

    string postfix, infix;

    cout << "Enter an Infix Expression : ";
    cin >> infix;

    stack<char> ExpStack;

    cout << "INFIX EXPRESSION : " << infix << endl;

    postfix = infixToPostfix(ExpStack, infix);

    cout << "POSTFIX EXPRESSION : " << postfix << endl;
}