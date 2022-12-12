/*

Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array

*/

// Name : Soham Arun Kulkarni
// RollNo.:31
// Div:B

#include <iostream>
using namespace std;
#define M 5

class CircularQueue
{
private:
    int cQueue[M];
    int front, rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(int);
    void dequeue();
    void display();
};

bool CircularQueue::isEmpty()
{
    return (front == -1 && rear == -1);
}

bool CircularQueue::isFull()
{
    return (rear + 1) % M == front;
}

void CircularQueue::enqueue(int val)
{

    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }

    else if (isEmpty())
        front = rear = 0;

    else
        rear = (rear + 1) % M;

    cQueue[rear] = val;

    cout << "enqueued " << val << endl
         << endl;
}

void CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % M;

    cout << endl
         << "dequeued " << cQueue[front] << endl
         << endl;
    cout << "Updated ";
    display();
}

void CircularQueue::display()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue is :  ";

        for (int i = front; i != rear; i = (i + 1) % M)
            cout << cQueue[i] << " ";
        cout << cQueue[rear];
        cout << endl;
        cout << endl;
    }
}

int main()
{

    CircularQueue queue_list;
    while (true)
    {
        int x;
        cout << "1. Place an order" << endl
             << "2. Serve an order" << endl
             << "3. Display Order List" << endl
             << "0. Exit" << endl
             << endl;

        int ch;
        cout << "Enter choice    ";
        cin >> ch;

        switch (ch)
        {

        case 1:
            cout << "   ==>Enter data  ";
            cin >> x;
            cout << endl;
            queue_list.enqueue(x);
            break;

        case 2:
            queue_list.dequeue();
            break;

        case 3:
            queue_list.display();
            break;

        case 0:
            cout << ". . . . . Terminating . . . . ." << endl;
            exit(0);

        default:
            cout << "Invalid choice" << endl
                 << "Let's try again" << endl
                 << endl;
        }
    }
    return 0;
}