/*

Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.

*/

#include <iostream>
#include <windows.h>
using namespace std;
#define M 5

class Queue
{
    int arr[M], front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }

    bool isEmpty();
    bool isFull();
    void enQueue(int);
    void deQueue();
    void display();
};

bool Queue::isEmpty()
{
    return front == -1 && rear == -1;
}

bool Queue::isFull()
{
    return rear == M - 1;
}

void Queue::enQueue(int val)
{

    if (isFull())
    {

        cout << "Overflow" << endl;
        return;
    }
    else if (isEmpty())
    {
        front++;
        rear++;
    }
    else
    {
        rear++;
    }

    arr[rear] = val;
}

void Queue::deQueue()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
    {
        front++;
    }
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Empty" << endl;
        return;
    }
    cout << "Queue is : ";
    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    Queue q;

    while (true)
    {

        cout << "   Queue Operations" << endl;
        cout << "1-Insert Job" << endl;
        cout << "2-Delete Job" << endl;
        cout << "3-Display Queue" << endl;

        int ch;
        cout << "Enter choice\t";
        cin >> ch;
        cout << endl;

        switch (ch)
        {

        case 1:
            int x;
            cout << "==>Enter data\t";
            cin >> x;
            cout << endl;
            q.enQueue(x);
            q.display();
            break;

        case 2:
            q.deQueue();
            q.display();
            break;
        case 3:
            q.display();
            break;
        case 0:
            cout << "---Terminating---" << endl;
            Sleep(10000);
            exit(0);
        default:
            cout << "Invalid choice. Let's try again" << endl;
        }
    }
}