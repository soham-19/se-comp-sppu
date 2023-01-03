#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item
{
    public:
        int code;
        int quantity;
        float cost;
        string name;

    
        bool operator <(const Item &i)
        {
            return code < i.code;
        }
        bool operator ==(const Item &i){
            return code == i.code;
        }
};

vector <Item> v;

void insert();
void delete_();
void display();
void print(Item&);
void search();

int main(){

    while (true)
    {
        cout << "MAIN MENU\n1.insert\n2.display\n3.sort\n4.search\n5.delete\n0.exit\n\n->CHOICE = ";
        int xh;
        cin >> xh;

        switch(xh){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                cout << "BEFORE :\t";
                display();
                sort(v.begin(),v.end());
                cout << "AFTER : \t";
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                delete_();
                break;
            case 0:
                exit(0);
            default:
                cout << "AGANN KAR BHAI\n\n";
        }
    }
    
}

void insert()
{
    Item obj;
    cout << "Enter code : ";
    cin >> obj.code;
    cout << "ENter name : ";
    cin >> obj.name;
    cout << "Enter cost : ";
    cin >> obj.cost;
    cout << "Enter quantity : ";
    cin >> obj.quantity;

    v.push_back(obj);
}

void display()
{   cout << "CODE\tNAME\tCOST\tQUANTITY\n";
    for_each(v.begin(),v.end(),print);
}

void print(Item & obj)
{
    cout << "#"<<obj.code << "\t" << obj.name << "\t" << obj.cost << "\t" << obj.quantity <<endl;
    cout << "------------------------------\n";
}

void search(){

    Item obj;
    cout << "Enter key : ";
    cin >> obj.code;

    vector<Item> :: iterator it = find(v.begin(),v.end(),obj);

    if( it == v.end())
        cout << "#" << obj.code  << " not found!!\n";
    else 
        cout << "#" << obj.code << " found in records!!\n";
}

void delete_()
{
    Item obj;
    cout << "Enter key to delete : ";   cin >> obj.code;

    vector <Item> ::iterator it = find(v.begin(),v.end(),obj);

    if( it == v.end())
        cout << "#" << obj.code  << " not found!!\n";
    else 
        {
            cout << "deleted #" << it->code << "fromm data!!\n\n";
            v.erase(it);
        }
}