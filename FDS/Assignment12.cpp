#include <iostream>
using namespace std;
#define M 5
class C_QUEUE{

    int cq [M], front, rear;

    public:

        C_QUEUE(){
            front = rear = -1;
        }

        bool empty();
        bool full();
        void enqueue(int);
        void dequeue();
        int front_();
        int rear_();
        void print();
};

int C_QUEUE::front_(){
    return front;
}

int C_QUEUE::rear_(){
    return rear;
}

bool C_QUEUE::empty(){
    return front == -1;
}

bool C_QUEUE::full(){
    return front == (rear+1)%M;
}

void C_QUEUE::enqueue(int val){

    if(full()){
        cout << "fullllll\n";
        return;
    }
    else if(empty()){
        front = rear = 0;
    }
    else{
        rear = (rear+1)%M;
    }

    cq[rear] = val;
}

void C_QUEUE::dequeue(){
    if(empty()){
        cout << "emptyyyyyyyy\n";
        return;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%M;
    }
}

void C_QUEUE::print(){
        if (empty()){
            cout << " queue is emptyyyyyyy\n" << endl;
            return;    
            }
    cout << "\t\tQueue is : ";

    int i = front;
    while(i!=rear){
        cout << cq[i]<<" ";
        i = (i+1)%M;
    }
    cout << cq[rear]<< endl;
}

int main()
{

    C_QUEUE queue_list;
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
            queue_list.print();
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
/*
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    1
   ==>Enter data  1

1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    1
   ==>Enter data  3

1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    1
   ==>Enter data  4

1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    1
   ==>Enter data  5

1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    1
   ==>Enter data  6

1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    1
   ==>Enter data  7

fullllll
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    3
                Queue is : 1 3 4 5 6
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    2
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    3
                Queue is : 3 4 5 6
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    2
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    3
                Queue is : 4 5 6
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    2
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    3
                Queue is : 5 6
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    2
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    3
                Queue is : 6
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    2
1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    3
 queue is emptyyyyyyy

1. Place an order
2. Serve an order
3. Display Order List
0. Exit

Enter choice    4
Invalid choice
Let's try again

1. Place an order
2. Serve an order
3. Display Order List
0. Exit

*/