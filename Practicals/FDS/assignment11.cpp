/*

Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system.
If the operating system does not use priorities, then the jobs are processed in the order they enter the system.
Write C++ program for simulating job queue. Write functions to add job and delete job from queue.

*/

// Name : Soham Arun Kulkarni
// RollNo.:31
// Div:B

#include <iostream>
using namespace std;
#define M 10

class Queue
{
private:
    int data[M];
    int front, rear;

public:
    Queue()
    {
        this->front = this->rear = -1;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(int);
    void dequeue();
    void display();
};
bool Queue::isEmpty()
{
    return (front == -1 && rear == -1);
}
bool Queue::isFull()
{
    return (rear == M - 1);
}
void Queue::enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if (front == -1)
        front++;

    data[++rear] = val;
        cout << "enqueued " << val << endl << endl;
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        cout <<endl<< "dequeued " << data[front] << endl << endl;
        front++;
    }

    cout << "Updated ";
    display();
}

void Queue::display()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue is :  ";

        for (int i = front; i <= rear; i++)
            cout << data[i] << " ";
        cout << endl;
        cout << endl;
    }
}

int main()
{

    Queue queue_list;
    while (true)
    {
        cout << "1. Enter job" << endl
             << "2. Delete job" << endl
             << "3. Display Queue" << endl
             << "0. Exit" << endl
             << endl;

        int ch;
        cout << "Enter choice    ";
        cin >> ch;

        switch (ch)
        {

        case 1:
            int x;
            cout << "   ==>Enter data  ";
            cin >> x;
            cout<<endl;
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