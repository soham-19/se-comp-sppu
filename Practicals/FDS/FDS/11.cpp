#include <iostream>
using namespace std;

class Node{
    int data;
    Node * next;

    public :
        Node( int x){
            data = x;
            next = NULL;
        }
    friend class Queue;
};

class Queue{
    Node * front, * rear;

    public:
        Queue(){
            front = rear = NULL;
        }

        void enqueue(int);
        void print();
        void dequeue();
};

void Queue::enqueue(int x){

    Node *ptr = new Node(x);

    if (front == NULL){
        front = rear = ptr;
    }
    else{
        rear->next = ptr;
        rear = ptr;
    }
}

void Queue::dequeue(){
    if(front == NULL)
        cout << "Cant delete!!\n";

    else{
        Node * temp = front;

        front = front->next;

        delete temp;
    }
}

void Queue::print(){
    if(front == NULL)
        cout << "Empty!!!!";

    else{

        Node * temp = front;
        cout << "Queue is : ";
        while(temp != rear->next) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

}

int getInt(){
    cout << "Enter data\n-> ";
    int x;
    cin >> x;

    return x;
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