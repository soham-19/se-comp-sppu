#include<iostream>
#include<map>
#include<iterator>
using namespace std;

void insertState(map<string,int> &population_map){

    int pop;
    string state;
    cout << "\tState : " << endl;
    cout << "\t  -> Name : ";
    cin >> state;
    cout << "\t  ->Population : ";
    cin >> pop;
    population_map[state] = pop;
    cout << "State added to the map !\n";
}
void addStates(map<string,int> &pop_map){

    int n;
    cout << "How many States do you want to add to population map ? ";
    cin >> n;
    
    for (int i =0; i<n; i++)
        insertState(pop_map);

}

void displayMap(map<string,int> population_map){

    map <string,int> :: iterator it;
    cout << "State : Population\n";

    for(it = population_map.begin(); it != population_map.end(); it++)
        cout << it->first << " : " << it->second << endl;

    cout << endl;
}

void searchState(map<string,int> pop_map){

    string key;
    map<string,int> :: iterator it;

    cout << "Enter state name to search : ";
    cin >> key;

    it = pop_map.find(key);

    if(it != pop_map.end())
        cout << key << " found in map!!\n";
    else
        cout << key << " not found in map!!\n";

}
int main(){

    map <string,int> population_map;
    int ch;
    while(true){

        cout << "* * * <M A I N*M E N U> * * *\n";
        cout << "1-Add multiple States\n";
        cout << "2-Add single State\n";
        cout << "3-Display States\n";
        cout << "4-Search State\n";

        cout << "Enter your choice\n-> ";
        cin >> ch;

        switch(ch){

            case 1:
                addStates(population_map);
                break;
            case 2:
                insertState(population_map);
                break;
            case 3:
                displayMap(population_map);
                break;
            case 4:
                searchState(population_map);
                break;
        }
    }
    return 0;
}