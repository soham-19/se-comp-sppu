#include<iostream>
using namespace std;

class Node{
    int data;
    Node * next;

    public:

    Node(int n){
        data = n;
        next = NULL;
    }
    Node (){
        cout << "Enter data : ";
        cin >> data;
        next = NULL;
    }

    friend class Queue;
};

class Queue{
    Node * front;
    Node * rear;

    public:

    Queue(){
        front = rear = NULL;
    }

    void enqueue(int x){

        Node * newPtr = new Node(x);
        if(front == NULL){

            front = rear = newPtr;
        }
        else{
            rear->next = newPtr;
            rear = rear->next;
        }
    }

    void dequeue(){

        if(front == NULL){
            cout << "Queue is empty\n";
            return;
        }
        else if(front == rear){
            delete front;
            front = rear = NULL;
            return;
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

int getInt(){
    int ele;
    std::cout << "Enter element : ";
    std::cin >> ele;
    return ele;
}

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