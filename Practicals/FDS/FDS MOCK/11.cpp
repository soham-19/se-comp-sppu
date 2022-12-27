#include <iostream>
using namespace std;
#define M 5
class Queue
{
    int *data, front, rear;

public:
    Queue()
    {
        data = new int[M];
        front = rear = -1;
    }

    void display()
    {
        if (empty())
        {
            cout << "ENPTYYYYYY\n";
            return;
        }
        cout << "Queue is : ";
        for (int i = front; i <= rear; i++)
            cout << data[i] << " ";
        cout << endl;
    }
    bool empty()
    {
        return front == -1;
    }

    bool full()
    {
        return rear == M - 1;
    }
    void enqueue(int x)
    {
        if (full())
        {
            cout << "fulllllllllllllllll\n";
            return;
        }
        else if (empty())
            front = rear = 0;
        else
            rear++;

        data[rear] = x;
    }

    void dequeue()
    {
        if (empty())
        {
            cout << "Emptyyyyyy\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
};
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