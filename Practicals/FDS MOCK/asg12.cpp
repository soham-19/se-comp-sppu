/*

Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array

*/

#include <iostream>
#define M 5
using namespace std;

class C_Queue
{
    int arr[M], front, rear;

public:
    C_Queue()
    {
        front = rear = -1;
    }

    bool isEmpty();
    bool isFull();
    void enq(int);
    void deq();
    void disp();
};

bool C_Queue::isEmpty()
{
    return front == -1 && rear == -1;
}
bool C_Queue::isFull()
{
    return (rear + 1) % M == front;
}

void C_Queue::enq(int x)
{
    if (isFull())
    {
        cout << "C-Queue is full\n";
        return;
    }

    else if (isEmpty())
        front = rear = 0;

    else
        rear = (rear + 1) % M;

    arr[rear] = x;
}

void C_Queue::deq()
{
    if (isFull())
        cout << "Overflow\n";

    else if (front == rear)
        front = rear = -1;

    else
    {
        front = (front + 1) % M;
    }
}

void C_Queue::disp()
{
    if (isEmpty())
        cout << "Underflow\n";

    cout << "C-Q. is : ";

    for (int i = front; i != rear; i = (i + 1) % M)

        cout << arr[i] << " ";

    cout << arr[rear];
    cout << endl;
}
int main()
{

    C_Queue cq;

    while (true)
    {

        int x = (rand() % 10) + 1;

        cout << "   C-Queue Operations" << endl;
        cout << "1-Place Order" << endl;
        cout << "2-Delete Orders" << endl;
        cout << "2-Display Orders" << endl;

        cout << "==>Enter your choice\t";
        int ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
            cq.enq(x);
            cq.disp();
            break;

        case 2:
            cq.deq();
            cq.disp();
            break;
        case 3:
            cq.disp();
            break;
        case 0:
            cout << "Terminating" << endl;
            exit(0);
        default:
            cout << "Invalid choice\nLet's Try Agn\n";
        }
    }

    return 0;
}