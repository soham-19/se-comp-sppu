#include <iostream>
#define MAX 10
using namespace std;
class uh_can
{
public:
    int front, rear;
    int data[MAX];
    uh_can()
    {
        front == rear == -1;
    }
    int full()
    {
        if (rear == front - 1 || rear == MAX - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    int empty()
    {
        if (rear == front || rear == front == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void add()
    {
        if (full() == 0)
        {
            cout << "ENTER THE DATA:";
            if (front == -1 && rear == -1)
            {
                front = rear = 0;
                cin >> data[rear];
            }

            else
            {
                rear = (rear + 1) % 10;
                cin >> data[rear];
            }

            char c;
            cout << "WANT MORE!!";
            cin >> c;
            if (c == 'Y' || c == 'y')
            {
                add();
            }
            else
            {
                cout << "order are full!";
            }
        }
    }
    void serve()
    {
        if (empty() == 0)
        {
            if (front == rear) // first
            {
                cout << "order no serve:" << data[front] << endl;
                front == rear == -1;
            }
            else
            {
                cout << "order serve is:" << data[front];
                front = (front + 1) % 10;
            }
        }
        else
        {
            cout << "order is empty!";
        }
    }
    void display()
    {
        if (empty() == 0)
        {

            for (int i = front; i != rear; i = (i + 1) % 10)
            {
                cout << "order id are :" << i + 1 << "=>" << data[i] << endl;
            }
            cout << data[rear];
        }
        else
        {
            cout << "order is empty:";
        }
    }
    void check()
    {
        char k;
        int ch;

        cout << "======================>PIZZA<=========================" << endl;
        cout << "1]add \n 2]display \n 3]serve \n 4]exit \n";
        cout << "enter the choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            serve();
            break;
        case 4:
            exit(0);
            break;
            check();
        }
        cout << endl;
        cout << "WAANT TO CONTI::";
        cin >> k;
        if (k == 'Y' || k == 'y')
        {
            check();
        }
    }
};
int main()
{
    uh_can obj;
    obj.check();
    return 0;
}
