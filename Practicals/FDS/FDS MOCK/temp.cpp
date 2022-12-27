#include <iostream>
#define max 10
using namespace std;
    int prior(char ch)
    {
        if (ch == '*' || ch == '/')
        {
            return 2;
        }
        else if (ch == '+' || ch == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
class stack
{
public:
    char s[max];
    int top;

    bool empty()
    {
        return top == -1;
    }
    stack()
    {
        top = -1;
    }
    char push(char x)
    {
        s[++top] = x;
    }
    void pop()
    {
        top--;
    }
    char peek()
    {
        return s[top];
    }
    bool is_operator(char ch)
    {
        return ch == '+' || ch == '*' || ch == '-' || ch == '/';
    }

    bool operand(char i)
    {
        return (('a' <= i && 'z' >= i) || 'A' <= i && 'z' >= i || ('0' <= i && '9' >= i));
    }
    friend int prior(char ch);
    friend string infixToPostfix( stack &s, string infix );
    
};

string infixToPostfix(stack &s, string infix) {
        string postfix; // s.push,pop,empty;.peek
        for (int i = 0; i < infix.length(); i++)
        {
            if (s.operand(infix[i]))
            {
                postfix += infix[i];
            }
            else if (infix[i] == '(')
            {
                s.push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!s.empty() && s.peek() == '(')
                {
                    postfix += s.peek();
                    s.pop();
                }
                if (s.peek() == '(')
                {
                    s.pop();
                }
            }
            else if (s.is_operator(infix[i]))
            {
                
                    if (s.empty())
                    {
                        s.push(infix[i]);
                    }
                
                else
                {
                    if (prior(infix[i]) > prior(s.peek())) //+*
                    {
                        s.push(infix[i]);
                    }
                    else
                    {
                        while (!s.empty() && prior(infix[i]) <= prior(s.peek()))
                        {
                            postfix += s.peek();
                            s.pop();
                        }

                        s.push(infix[i]);
                    }
                }
            }
        }
        while(!s.empty())
        {
            postfix+=s.peek();
            s.pop();
        }
        return postfix;
    }
int main()
{
    stack Stack;
    string infix, postfix;
    cout << "enter infix expression:";
    cin >> infix;
    postfix = infixToPostfix(Stack, infix);
    cout << "req postfix is:" << postfix;
    return 0;
}
// try_in.cpp