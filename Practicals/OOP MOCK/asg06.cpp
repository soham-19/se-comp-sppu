/*
Write C++ program using STL for sorting and
searching user defined records such as Item records
(Item code, name, cost, quantity etc) using vector container.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{
    public:

        int code;
        string name;
        float cost;
        int quantity;

        bool operator==(const Item &i){
            if(code == i.code)
                return true;
            return false;
        }

        bool operator< (const Item &i) {
            if(code < i.code)
                return true;
            return false;
        }
};

void insert();
void delete_item();
void search();
void print(Item&);
void display();

vector <Item> vect;

int main(){

    while(true){

            cout << "\n     M E N U\n"
                 << "1-push_back\n"
                 << "2-delete item\n"
                 << "3-search item"
                 << "4-sort items\n"
                 << "5-display\n"
                 << "0-exit()\n\n";

            int choice;

            cout << "Enter your choice\n==> ";
            cin >> choice;

            switch(choice){

                case 1:
                    insert();
                    break;
                
                case 2:
                    delete_item();
                    break;
                
                case 3:
                    search();
                    break;

                case 4:
                    cout << "Before sorting :\n";
                    display();
                    sort(vect.begin(),vect.end());
                    cout << "After sorting :\n";
                    display();
                    break;

                case 5:
                    display();
                    break;
                
                case 0:
                    cout << " T E R M I N A T I N G\n";
                    exit(0);

                default:
                    cout << "Invalid selection!\nLet's Try Again!!\n";
                
            }
    }
}

void insert(){

    Item obj;

    cout << "Enter code : ";
    cin >> obj.code;
    cout << "Enter name : ";
    cin >> obj.name;
    cout << "Enter cost : ";
    cin >> obj.cost;
    cout << "Enter quantity : ";
    cin >> obj.quantity;

    vect.push_back(obj);
}

void print(Item &obj) {

    cout << "\tCode : #" << obj.code << endl;
    cout << "\tName : " << obj.name << endl;
    cout << "\tCost : " << obj.cost << endl;
    cout << "\tQuantity : " << obj.quantity << endl << endl ;
}

void display(){
    for_each(vect.begin(), vect.end(), print);
}

void search() {

    Item o;
    cout << "Enter code key : ";
    cin >> o.code;


    vector <Item> :: iterator itr;
    itr = find(vect.begin(),vect.end(),o);

    if( itr == vect.end())
        cout << "Item not found in records!!\n";
    
    else
        cout << "Item found!!\n";
    

}

void delete_item(){

    Item o;

    cout << "Enter key code : ";
    cin >> o.code;

    vector <Item> :: iterator itr;

    itr = find(vect.begin(), vect.end(), o);

    if( itr == vect.end())
        cout << "Can't delete!!\nItem not found!!\n";
    
    else{
        cout << "Item deleted from record\n";
        vect.erase(itr);
    }
}