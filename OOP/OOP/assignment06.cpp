#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item {
    
    public:

        string name;
        int cost;
        int quantity;
        int code;

        // overloading the operators 

        bool operator==(const Item &obj){
            
            if(code == obj.code)
                return true;
            
            return false;
        }

        bool operator <(const Item &obj){

            if(code < obj.code)
                return true;

            return false;
        }
};

void insert();
void print(Item &o);
void display();
void deleteItem();
void search();

vector<Item> vec;

int main() {

    int ch;

    while(true) {

            cout << "     V E C T O R   O P E R A T I O N S" << endl
                 << "1-Insert" << endl
                 << "2-Display" << endl
                 << "3-Search" << endl
                 << "4-Sort" << endl
                 << "5-Delete" << endl
                 << "0-Exit" << endl
                 << endl;

            cout << "Enter your choice : ";
            cin >> ch;

            switch(ch) {

                case 0:
                    cout << endl << "   T E R M I N A T I N G"<<endl;
                    exit(0);

                case 1:
                    insert();
                    break;
                
                case 2:
                    display();
                    break;
                
                case 3:
                    search();
                    break;
                
                case 4:
                    cout << "Before Sorting :\n";
                    display();
                    
                    sort(vec.begin(), vec.end());

                    cout << "After sorting :\n";
                    display();
                    break;

                case 5:
                    deleteItem();
                    break;

                default:
                    cout << "Invalid selection!\nLet's try again !!\n\n";
            }
    }
}

void insert() {

    Item obj;

    cout << "Enter name : ";
    cin >> obj.name;

    cout << "Enter quantity : ";
    cin >> obj.quantity;

    cout << "Enter cost : ";
    cin >> obj.cost;

    cout << "Enter code : ";
    cin >> obj.code;

    vec.push_back(obj);
}

void print(Item &i) {

    cout << "   Code : #"<<  i.code <<endl;
    cout << "   Name: "<<  i.name <<endl;
    cout << "   Cost : "<<  i.cost <<endl;
    cout << "   Quantity : "<<  i.quantity <<endl;
    cout << endl;
}

void display() {

    for_each( vec.begin(), vec.end(), print);

}

void search() {

    Item keyObject;

    cout << "Enter #code for which you want to search : ";
    cin >> keyObject.code;

    vector<Item> :: iterator it = find(vec.begin(), vec.end(), keyObject);

    if(it == vec.end())

        cout << "#" << keyObject.code << " not found in records !!\n";
    
    else

        cout << "#" << keyObject.code << " exists in records !!\n";
}

void deleteItem() {

    Item keyObject;

    cout << "Enter the #code which you wish to delete from the records : ";
    cin >> keyObject.code;

    vector<Item> :: iterator it = find(vec.begin(), vec.end(), keyObject);

    if(it == vec.end()) {

        cout << "Can't perform deletion as #" << keyObject.code << " does't exist in records !!\n";

    }
    else {

        vec.erase(it);
        cout << "#" << keyObject.code << " deleted successfully !!\n";

    }

}