/*

A double-ended queue (deque) is a linear list in which additions and deletions may be made at
either end. Obtain a data representation mapping a deque into a one- dimensional array. Write
C++ program to simulate deque with functions to add and delete elements from either end of the
deque.

*/

// Name : Soham Arun Kulkarni
// RollNo.:31
// Div:B

#include <iostream>
using namespace std;
# define M 5

int getData();

class Dequeue {

    int data[M];
    int front;
    int rear;

    public:
        Dequeue(){
            front = rear = -1;
        }

        bool isFull();
        bool isEmpty();
        void insertAtFront(int);
        void insertAtRear(int);
        void deleteFromFront();
        void deleteFromRear();

        void display();
};

bool Dequeue::isEmpty(){
    return front == -1 && rear == -1;
}
bool Dequeue::isFull(){
    return (rear + 1 == front) || (front == 0 && rear == M-1);
}
void Dequeue::insertAtFront(int val){

    if(isFull()){
        cout << "Overflow"<<endl;
        return;
    }
    else if (isEmpty())
        front = rear = 0;

    else if (front == 0)
        front = M-1;
    
    else    
        front--;

    data[front] = val;
}
void Dequeue::insertAtRear(int val){

    if(isFull()) {
        cout << "Overflow"<<endl;
        return;
    }
    else if (isEmpty())
        front = rear = 0;
    
    else if (rear == M-1)
        rear = 0;
    
    else    
        rear = 0;

    data[rear] = val;
}

void Dequeue::deleteFromFront(){

    if(isEmpty()) {
        cout << "Underflow"<<endl;
        return;
    }

    else if( front == rear)
        front = rear = -1;
    
    else if (front == M-1)
        front = 0;
    
    else    
        front++;
}
void Dequeue::deleteFromRear(){

    if(isEmpty()){
        cout << "Underflow"<<endl;
        return;
    }

    else if(front == rear)
        front = rear = -1;

    else if(rear == 0)
        rear = M-1;

    else 
        rear--;
}
void Dequeue::display(){

    if(isEmpty()) {
        cout << "DE-Q is empty"<<endl;
        return;
    }
    cout << "DE-Q is :  ";
    for(int i=front; i!= rear; i= (i+1)%M)
        cout << data[i]<< " ";
    cout << data[rear];
}

int main () {

    int x, ch;
    Dequeue deque;

    while(true){
        cout << endl
             << "    DE-QUEUE OPERATIONS    " << endl
             << endl
             << "1-Insert At Front" << endl
             << "2-Insert At Rear" << endl
             << "3-Delete From Front" << endl
             << "4-Delete From Front" << endl
             << "5-Display" << endl
             << "0-Exit" << endl;
        cout << " ==>your choice ";
        cin >> ch;
        cout << endl;

        switch(ch){
            case 1:
                x = getData();
                deque.insertAtFront(x);
                break;
            case 2:
                x = getData();
                deque.insertAtRear(x);
                break;
            case 3:
                deque.deleteFromFront();
                break;
            case 4:
                deque.deleteFromRear();
                break;
            case 5:
                deque.display();
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

int getData(){

    cout << "   ==>Enter data  ";
    int x;
    cin >> x;
    cout << endl;
    return x;
}