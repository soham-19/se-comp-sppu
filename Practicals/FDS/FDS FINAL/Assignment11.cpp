#include<iostream>
using namespace std;

class Node{
    int data;
    Node * next;
    public:
    Node(int x){
        data = x;
        next = 0;
    }

    friend class Queue;
};

class Queue{
    Node * front, *rear;

    public:
    Queue(){
        front = rear = 0;
    }

    void enqueue(int x){
        Node * newNode = new Node(x);

        if (front == 0){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = rear->next;
        }
    }

    void dequeue(){
        if(front == NULL){
            cout << "mpy";
            return;
        }
        if(front == rear){
            delete front;
            front = rear = 0;
        }
        else{
            Node * temp = front;
            front = front->next;
            delete temp;
        }
    }

        void print(){

        if(front == NULL){
            cout << "Queue is empty\n";
            return;
        }
        Node * temp = front;

        cout << "Queue is : ";

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << endl;
    }
};
int getInt();
int main(){
    Queue q;
    
    while(true){
        int ch;

        cout << "    M A I N   M E N U\n";
        cout << "1-enqueue\n";
        cout << "2-dequeue\n";
        cout << "3-display\n";
        cout << "4-exit\n";
        cout << "Enter your choice : ";
        cin >> ch;

        switch(ch){
            case 1:
                q.enqueue(getInt());
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.print();
                break;

            case 4:
            exit(0);

            default:
            cout << "Invalid selection !!\n";
        }
    }
}


int getInt(){
    int ele;
    cout << "Enter element : ";
    cin >> ele;
    return ele;
}