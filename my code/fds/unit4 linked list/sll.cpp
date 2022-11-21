#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node * next;

        node () {
            cout << endl;
            cout << "Enter data :\t";
            cin>>this->data;
            this->next = NULL;
        }

        node (int val)  {
            this->data = val;
            this->next = NULL;
        }
};

class sll {
    private:
        node* head;
    public:
        void create();
        void printList();
        void insertAtHead();
        void insertAtTail();
        void insertAfterElement();
        void deleteFromHead();
        void deleteFromEnd();
        void deleteEle();
        void search();
        void swapAlt();

        sll() {
            this->head = NULL;
        }
};

void sll::create() {
    node * temp, * newNode;

    int choice = 1;

    while (choice) {
        newNode = new node();

        if ( head == NULL) {
            temp = head = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }

        cout << "\t\t\t\t\t\t\t\t\t\t\tContinue   0 | 1 :\t";
        cin >> choice;
    }

}

void sll::printList() {
    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }
    
    node * temp = this->head;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
        cout << "NULL\n";
}

void sll ::insertAtHead () {
    
    node* newNode = new node;
    if ( head != NULL) {
        newNode->next = head;
    }
        head = newNode;
    
}

void sll::insertAtTail() {
    if (head == NULL) {
        insertAtHead();
        return;
    }
    node*  temp;
    for (temp = head; temp->next != NULL; temp = temp->next) {}

    temp->next = new node();
    
}

void sll::insertAfterElement() {

    if (head == NULL) {
        cout << "List is empty... So no node to find... creating head node...\n\n";
        insertAtHead();
    }


    cout << "Enter the key :\t";
    int key;
    cin >> key;

    node *temp = head;

    while ( temp->data != key ) {
        temp = temp->next;
    }

    // node * nextNode = temp->next;
    node* newNode = new node();
    newNode->next = temp->next;
    temp->next = newNode;
}

void sll::deleteFromHead() {
    if (head == NULL) {
        cout << "List is empty... So no node to delete...\n\n";
        return;
    }

    if (head->next == NULL) {
        head = NULL;
        cout << "List emptyed";
        return;
    }

    node *temp = head;
    head = head->next;

    delete temp;
}

void sll::deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty... So no node to delete...\n\n";
        return;
    }

    if (head->next == NULL) {
        head = NULL;
        cout << "List emptyed while deleting\n";
        return;
    }
    node * temp = head;
    node * prev = head;

    while ( temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    delete temp;
    
}

void sll::deleteEle() {
    if (head == NULL) {
        cout << "List is empty... So no node to delete...\n\n";
        return;
    }
    

    cout << "Enter the key :\t";
    int key;
    cin >> key;

    if(head->data == key){
        deleteFromHead();
        return;
    }

    node * Current = head;
    node * Prev = head;

    while ( Current->data != key ) {
        Prev = Current;
        Current = Current->next;
    }

    Prev->next = Current->next;

    delete Current;
}

void sll::search() {

    cout<<"Enter key\t";
    int key;
    cin >> key;

    node* temp = head;
    while (temp !=0){
        if(temp->data == key) {
            cout<<"Element present\n\n";
            return;
        }
        temp = temp->next;
    }
        cout <<"Element not present\n\n";
}

void sll::swapAlt() {
    if (head == 0 || head->next == 0)
        return;
    node *prev = head, *current = head->next;

    head = current;

    while(1) {
        node * temp = current->next;
        current->next = prev;

        if(temp == NULL || temp->next == NULL) {
            prev->next=temp;
            break;
        }
        prev->next = temp->next;

        prev = temp;

        current = prev->next;
    }
}

int main () {

    sll list;

    list.create();
        list.printList();


    while(true) {
    cout<<endl
        <<"...Enter choice..."<<endl
        <<"1.Add node at Beg"<<endl
        <<"2.Add node at end"<<endl
        <<"3.Add node after a node"<<endl
        <<"4.delete head node"<<endl
        <<"5.delete end node"<<endl
        <<"6.delete element node"<<endl
        <<"7.search element"<<endl
        <<"8.swap alternatives"<<endl
        <<"0.exit()"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
    {
    case 1:
        list.insertAtHead();
        list.printList();
        break;
    case 2:
        list.insertAtTail();
        list.printList();
        break;
    case 3:
        list.insertAfterElement();
        list.printList();
        break;
    case 4:
        list.deleteFromHead();
        list.printList();
        break;
    case 5:
        list.deleteFromEnd();
        list.printList();
        break;
    case 6:
        list.deleteEle();
        list.printList();
        break;
    case 7:
        list.search();
        list.printList();
        break;
    case 8:
        list.swapAlt();
        list.printList();
        break;
    case 0 :
        cout << ".....Terminating....."<<endl;
        exit(0);
        break;
    
    default:
    cout << "Invalid Operation.....\n\n";
        break;
    }
    }

    

    return 0;
}