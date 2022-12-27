#include <iostream>
using namespace std;

class stack
{
	int top;
	char STACK[100];

public:
	stack() { top = -1; }

	void push(char ch)
	{
		STACK[++top] = ch;
	}

	char peek() { return STACK[top]; }

	void pop() { top--; }

	bool empty() { return top == -1; }
};

bool isOperand(char i)
{
	return ((i >= '0' && i <= '9') || (i >= 'a' && i <= 'z') ||
			(i >= 'A' && i <= 'Z'));
}

bool isOperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int pre(char ch)
{

	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '+' || ch == '-')
		return 1;
	else
		return -1;
}
string infixToPostfix(stack &s, string infix)
{
	string postfix;

	for (int i = 0; i < infix.length(); i++)
	{
		if (isOperand(infix[i]))
			postfix += infix[i];

		else if (infix[i] == '(')
			s.push(infix[i]);
		else if (infix[i] == ')')
		{
			while (s.peek() != '(' && !s.empty())
			{
				postfix += s.peek();
				s.pop();
			}
			if (s.peek() == '(')
				s.pop();
		}

		else if (isOperator(infix[i]))
		{

			if (s.empty())
				s.push(infix[i]);
			else if (pre(infix[i]) > pre(s.peek()))
			{
				s.push(infix[i]);
			}
			else
			{
				while (!s.empty() && pre(infix[i]) <= pre(s.peek()))
				{
					postfix += s.peek();
					s.pop();
				}
				s.push(infix[i]);
			}
		}
	}

	while (!s.empty())
	{
		postfix += s.peek();
		s.pop();
	}
	return postfix;
}
int main()
{

	string infix, postfix;

	cout << "Enter infix expression : ";
	cin >> infix;

	stack s;

	postfix = infixToPostfix(s, infix);

	cout << "INFIX : " << infix << endl;
	cout << "POSTFIX : " << postfix << endl;

	if (postfix == "A7+IUOA-*n/-8P*+")
		cout << "SOhhhhhhhhhhhh";
	else
		cout << "Brooooooo glttttttttttt";
	return 0;
}

// A+7-(I*U(O-A)/n)+8*P