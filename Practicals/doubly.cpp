/*Write c++ program for storing binary number using doubly linked lists.
write functions
a) to compute 1's and 2's complement
b) add two binary numbers*/


#include<iostream>
using namespace std;

class Node{

    public:

    bool bit;
    Node *next, *prev;
    bool carry;
        Node(){
            cout << "Bit Value : 0/1 ? : ";
            cin >> bit;
            next = prev = NULL;
            carry = 0;
        }

};

class BinNum{

    public:

    Node * head, *tail;
    int noOfBits;

    BinNum(){
        head = tail = NULL;
        cout << "No of bits ? : ";
        cin >> noOfBits;
    }

    void addBit();
    void createNum();
    void printNum();
    void printonec();
    void printwoc();

};

void BinNum::addBit(){

    Node * newBit = new Node;
    if(head == NULL){
        head = tail = newBit;
    }
    else{
        tail->next = newBit;
        newBit->prev = tail;
        tail = tail->next;
    }
}
void BinNum::createNum(){

    for(int i=0; i<noOfBits; i++)
        addBit();
}

void BinNum::printNum(){

    Node * temp = tail;
    cout << "Original Num : ";
    while(temp != NULL){
        cout << temp->bit;
        temp = temp->prev;
    }
    cout << endl;
}
void BinNum::printwoc(){

    Node * temp = head;
    bool arr[noOfBits];
    int i=0;

    while(temp != NULL && temp->bit == false){
        arr[i++] = temp->bit;
        temp = temp->next;
    }
    arr[i++] = 1;
    temp = temp->next;
    if(temp != NULL){
        while(temp != NULL){

        arr[i++] = !temp->bit;
            temp = temp->next;
        }
    }
        cout << "2's complement : ";
    for(int j=noOfBits-1; j>=0; j--)
        cout <<arr[j];
    cout << endl;
}
void BinNum::printonec(){

    Node * temp = tail;
    cout << "1's complement : ";
    while(temp != NULL){
        cout << !temp->bit;
        temp = temp->prev;
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    BinNum a;
    a.createNum();

    a.printNum();
    a.printonec();
    a.printwoc();
    return 0;
}
