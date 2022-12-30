#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Item{

    public:
    int code;
    float price;
    int quantity;
    string name;

    bool operator<(const Item& o){
        return code < o.code;
    }

    bool operator==(const Item& o){
        return code==o.code;
    }

    friend void push_back();
    friend void print(Item);
};

vector <Item> v;

void push_back();
void search();
void dlt();
void print(Item);
void display();

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
                    // v.erase();
                    exit(0);

                case 1:
                    push_back();
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
                    
                    sort(v.begin(), v.end());

                    cout << "After sorting :\n";
                    display();
                    break;

                case 5:
                    dlt();
                    break;

                default:
                    cout << "Invalid selection!\nLet's try again !!\n\n";
            }
    }
}


void print(Item i){
    cout << "#" <<i.code <<" | "<< i.name<<" | "<<i.quantity<<" | "<<i.quantity << endl;
    cout <<"----------------------------------------------------------------------------"<<endl;
}
void push_back(){
    Item i;
    
    cout << "Enter code : ";
    cin >> i.code;

    cout << "Enter name : ";
    cin >> i.name;

    cout << "Enter price : ";
    cin >> i.price;

    cout << "Enter quantity : ";
    cin >> i.quantity;

    v.push_back(i);
}
void display(){

    for_each(v.begin(),v.end(),print);
}

void search(){
    cout << "Enter key code : ";
    Item key;
    cin >> key.code;

    vector <Item> :: iterator it;

    it = find(v.begin(),v.end(),key);

    if(it == v.end())
        cout << "not found!!\n\n";
    else
        cout << "found!!\n\n";
}

void dlt(){

    Item keyObject;

    cout << "Enter the #code which you wish to delete from the records : ";
    cin >> keyObject.code;

    vector<Item> :: iterator it;
    it = find(v.begin(),v.end(),keyObject);

    if(it == v.end())
        cout << "not found!!\n\n";
    else
        {
            v.erase(it);
            cout << "Deleted \n\n";
        }

}