#include <iostream>
#include <map>
using namespace std;

map<string,int> pop_map;
string state;
int pop;

void addState(string name)
{   
    cout << "Add population of " << name << " ";
    cin >> pop;

    pop_map[name] = pop;
}

void addStates(int n){
    for(int i=0; i<n; i++)
    {
        cout << "Enter state name : ";
        cin >> state;
        addState(state);
    }
}

void display()
{   cout << "STATE\t\t:\tPOPULATION\t\n";
    cout << "--------------------------------------------\n";
    for(map<string,int>::iterator it = pop_map.begin(); it != pop_map.end(); it++)
    {
        cout << (*it).first << "\t\t:\t" << it->second << endl;
        cout << "--------------------------------------------\n";
    }
}
void search()
{   
    cout << "Enter key \t";
    cin >> state;

    map<string,int> :: iterator it = pop_map.find(state);

    if(it == pop_map.end())
        cout << "NOT FOUND";
    else    
        cout << "FOUND";
}

void dlt()
{
    cout << "Enter key to delete: ";
    cin >> state;

    map<string,int>::iterator it = pop_map.find(state);
    if (it != pop_map.end())
        pop_map.erase(it);
    else
        cout << "Key not found" << endl;
}

int main() {

    while(true)
    {
        cout << "     MENU\n1.ADD MULTIPLE STATES\n2.ADD A STATE\n3.DISPLAY\n4.SEARCH\n5.DELETE STATE\nCHOICE : ";
        int ch;
        cin >> ch;

        switch(ch)
        {
            case 1:
                int n; 
                cout << "HOW MANY ? ";
                cin >> n;
                addStates(n);
                break;
            case 2:
                cout << "Enter state name : ";
                cin >> state;
                addState(state);
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                dlt();
                break;
            case 0:
                exit(0);
            default:
                cout << "Agian\n";
        }
    }
}