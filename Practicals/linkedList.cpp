/*
Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final year of department can be granted membership on request.
Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club.
Write C++ program to maintain club members information using singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as president or even secretary.   ✅
b) Compute total number of members of club                              ✅
c) Display members                                                      ✅
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists.
*/

#include<iostream>
using namespace std;

class Node{

	public:

	    int prn;
        string name;
	    Node * next;
	
	Node(){
		cout << "==>Enter PRN : ";
        cin >> prn;
		cout << "==>Enter NAME : ";
        fflush(stdin);
        getline(cin,name);
		next = NULL;
	}

};

class List{


    public:
    Node * president;
    Node * secretary;
    Node * lastMember;
    int count;

        List(){
            president = secretary = lastMember = NULL;
            count = 0;
        }

        void insertPresident();
        void insertAtTail();
        void create();
        void addMember();
        void deletePresident();
        void countMembers();
        void deleteSec();

        friend ostream& operator << (ostream&, List &);
    
    
};

ostream& operator << (ostream& out, List & linkedList){

    Node * temp = linkedList.president;

    if(temp == NULL)

        out << "LL is empty!\n";
    
    else{
        while( temp != NULL){
            out << "Name : "<< temp->name;
            out << "\tPRN : " << temp->prn;
            out << "\n";
            temp = temp->next;
        }

    }

}

void List::insertPresident(){

    count++;    
    Node * newNode = new Node();

    if(president == NULL){
        lastMember = NULL;
        president = secretary = newNode;
        return;
    }
    newNode->next = president;
    president = newNode;
}

void List::insertAtTail(){

    count++;    
    Node * newNode = new Node();

    if (secretary == NULL){
        lastMember = NULL;
        president = secretary = newNode;
        return;
    }
    lastMember = secretary;
    secretary->next = newNode;
    secretary = secretary->next;
}

void List::create(){
    char ch;
    do{
        insertAtTail();
        cout << "Enter 'y' to continue :  ";
        cin >> ch;
    }
    while(ch =='y' || ch =='Y');
}

void List::addMember(){

    count++;    
    Node * newNode = new Node;

    lastMember->next = newNode;
    newNode->next = secretary;
}

void List::deletePresident(){

    if(president == NULL){
        cout << "LL is empty can't delete!!\n";
        return;
    }
    Node * temp = president;
    president = president->next;
    delete temp;

    if(president == NULL)
        secretary = lastMember = president;

        count--;
}

void List::deleteSec(){

    Node * temp;
    if(president == NULL){
        cout << "LL is empty can't delete!!\n";
        return;
    }
    else if(president == secretary){
        temp = president;
        president = secretary = lastMember = NULL;
    }
    else{
        temp = president;

        while(temp->next != lastMember){
            temp = temp->next;
        }
        lastMember = temp;
        temp = secretary;
        secretary = lastMember->next;
    }
        secretary->next = NULL;
        delete temp;
        count--;
}
void List::countMembers(){
    cout << "Total Members : " << count << endl;
}

int main(int argc, char const *argv[])
{
    List LL;

    LL.create();        

    cout << LL;
    LL.deleteSec();
    cout << LL.lastMember->name<<"\n";
    LL.countMembers();
    cout << LL;
    // LL.deleteSec();
    // cout << LL;

    return 0;
}
