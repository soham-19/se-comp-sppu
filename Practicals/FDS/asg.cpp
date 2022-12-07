/*
Department of Computer Engineering has students' club named 'Pinnacle Club'
Students of second, third and final year of department can be granted membership
on request. Similarly one may cancel the membership of club. First node is
reserved for president of club and last node is reserved for secretary of club. Write
C++ program to maintain club member‘s information using singly linked list. Store
student PRN and Name. Write functions to:
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Two linked lists exists for two divisions. concatenate two lists.
*/

// Name : Soham Arun Kulkarni.
// Roll No. SE-B-31

#include <iostream>
#include <string>
using namespace std;

class node
{

public:
    // demo
    
    string name;
    string prn;
    node *next;

    node()
    {
        cout << "Enter data :" << endl;
        cout << "==> Enter name  ";
        fflush(stdin);
        getline(cin, name);
        cout << endl;
        cout << "==> Enter prn no.  ";
        fflush(stdin);
        getline(cin, prn);
        // cout<<endl;
        cout << "node created.....\n";
        next = NULL;
    }
};

class PinnacleClub
{
public:
    node *head;

    PinnacleClub()
    {
        head = NULL;
    }

    void insertAtTail();
    void insertAtHead();
    void createClub();
    void print();
    int count();
};
int PinnacleClub::count(){
    node* temp = head;
    int count = 0;
    while(temp!=0){
        temp = temp->next;
        count++;
    }
    return count;
}
void PinnacleClub::insertAtTail()
{
    if (head == NULL)
    {
        insertAtHead();
        return;
    }
    node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next)
    {
    }

    temp->next = new node();
}

void PinnacleClub::insertAtHead()
{

    node *newNode = new node;

    if (head != NULL)
        newNode->next = head;

    head = newNode;
}

void PinnacleClub::createClub()
{
    int ch;
    do
    {
        insertAtTail();
        cout << "Continue ? 0/1   ";
        cin >> ch;
    } while (ch);
}

void PinnacleClub::print()
{
    if (head == NULL)
    {
        cout << "Records are empty" << endl;
        return;
    }
    else
    {
        node *temp = head;

        while (temp != 0)
        {
            if (temp == head)
                cout << endl
                     << "PRESIDENT :" << endl;
            if (temp->next == NULL)
                cout << endl
                     << "SECRETARY :" << endl;

            cout << "\tName : " << temp->name << "\t"
                 << "PRN : " << temp->prn << endl;
            if (temp == head)
                cout << endl
                     << "MEMBERS :" << endl;
            temp = temp->next;
        }
    }
}

int main () {

    int x, ch;
    PinnacleClub club1;

    while(true){
        cout << endl
             << "    PINNACLE CLUB    " << endl
             << endl
             << "1-Add Member" << endl
             << "2-Delete Member" << endl
             << "3-Count Members" << endl
             << "4-Delete From Front" << endl
             << "5-Merge Clubs" << endl
             << "0-Exit" << endl;
        cout << " ==>your choice ";
        cin >> ch;
        cout << endl;

        // switch(ch){
        //     case 1:
        //         x = getData();
        //         deque.insertAtFront(x);
        //         break;
        //     case 2:
        //         x = getData();
        //         deque.insertAtRear(x);
        //         break;
        //     case 3:
        //         deque.deleteFromFront();
        //         break;
        //     case 4:
        //         deque.deleteFromRear();
        //         break;
        //     case 5:
        //         deque.display();
        //         break;
        //     case 0:
        //         cout << ". . . . . Terminating . . . . ." << endl;
        //         exit(0);
        //     default:
        //         cout << "Invalid choice";
        //         break;
        // }
    }
    return 0;
}
