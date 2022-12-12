/*
A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a
droop” is a palindrome, as can be seen by examining the characters “poor danisina
droop” and observing that they are the same forward and backward. One way to check
for a palindrome is to reverse the characters in the string and then compare with
them the original-in a palindrome, the sequence will be identical. Write C++
program with functions-
a) To print original string followed by reversed string using stack
To check whether given string is palindrome or not
*/

#include <iostream>
#include <string.h>

using namespace std;

class Char_Stack
{
    char stk[100];
    int top;

    public:
        Char_Stack(){
            top = -1;
        }

    void push(char) ;
    void convert(char[]);
    void reverse(char []);
    void palindrome(char[]);
    void remove(char[]);
};

void Char_Stack::remove(char str[]) {

    int count = 0;

    for(int i=0; i<strlen(str); i++){

            if (str[i] > 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
                str[count++] = str[i];
    }
    str[count] = '\0';

}
void Char_Stack::convert(char str[]) {

    remove(str);

    for( int i=0; i<strlen(str); i++) {

            if( str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
    }
}

void Char_Stack::push(char x) {

    stk[++top] = x;
    cout << x << " pushed on stack\n";
}

void Char_Stack::palindrome(char str[]) {

    convert(str);
    cout << "str : "<<str<<endl;

    int i = 0;

    while(i<strlen(str))
        push(str[i++]);

    char temp [100] = "\0";

    int j = 0;

    while(top != -1) {

        temp[j++] = stk[top--];
    }

    temp[j] = '\0';

    cout << "Reversed string : " << temp << endl;

    if(strcmp(str,temp) == 0)
        cout << str << " is palindrome\n";
    else
        cout << str << " is not palindrome\n";

    
}

main() {

    Char_Stack obj;

    char str[100];
    
    cout << "Enter the string :  ";

    cin.getline(str,50);

    obj.palindrome(str);

}