/*

A double-ended queue (deque) is a linear list in which additions and deletions may be made at
either end. Obtain a data representation mapping a deque into a one- dimensional array. Write
C++ program to simulate deque with functions to add and delete elements from either end of the
deque.

*/
#include<iostream>
#define M 5
using namespace std;

class DQ{

    int * arr, front , rear;


    public:

    DQ(){
        arr = new int[M];
        front = rear = -1;
    }

    ~DQ(){
        delete [] arr;
    }

    bool full();
    bool empty();
    
    void addF(int);
    void addR(int);
    void delF();
    void delR();

    void print();
};

bool DQ::empty(){
    return front == -1 && rear == -1;
}

bool DQ::full(){
    return (front==0 && rear == M-1) || (front == rear+1);
}

void DQ::print(){
    int i = front;
    while(i!=rear){
        cout << arr[i]<< " ";
        i = (i+1)%M;
    }
    cout << arr[rear];
}

void DQ::addF(int val){
    if(full()){
        cout << "fullllll\n";
        return;
    }
    else if(empty()){
        front = rear = 0;
    }
    else if(front == 0){
        front = M-1;
    }
    else{
        front--;
    }

    arr[front] = val;
}

void DQ::addR(int val){
    if(full()){
        cout << "fullllll\n";
        return;
    }
    else if(empty()){
        front = rear = 0;
    }
    else if(rear == M-1){
        rear = 0;
    }
    else{
        rear++;
    }

    arr[rear] = val;
}

void DQ::delF(){
    if(empty()){
        cout << "empty\n";
        return;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(front == M-1){
        front = 0;
    }
    else{
        front++;
    }

}

void DQ::delR(){
    if(empty()){
        cout << "empty\n";
        return;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = M-1;
    }
    else{
        rear--;
    }
}

int getData();

int main () {

    int x, ch;
    DQ deque;

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
                deque.addF(x);
                break;
            case 2:
                x = getData();
                deque.addR(x);
                break;
            case 3:
                deque.delF();
                break;
            case 4:
                deque.delR();
                break;
            case 5:
                deque.print();
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
/*

    DE-QUEUE OPERATIONS    

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 1

   ==>Enter data  3


    DE-QUEUE OPERATIONS    

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 2

   ==>Enter data  5


    DE-QUEUE OPERATIONS    

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 2

   ==>Enter data  3


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 1

   ==>Enter data  7


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 1

   ==>Enter data  9


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 3


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 3


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 4


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 4


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 5

3
    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 5

3
    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 1

   ==>Enter data  99


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 5

99 3
    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 2

   ==>Enter data  88


    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 5

99 3 88
    DE-QUEUE OPERATIONS

1-Insert At Front
2-Insert At Rear
3-Delete From Front
4-Delete From Front
5-Display
0-Exit
 ==>your choice 0

. . . . . Terminating . . . . .
*/