#include<iostream>
#include<string>
#include<map>
#include<iterator>
using namespace std;

int main(){
    int n, pop;
    string state;

    map<string,int> population_map;

    cout << "Enter the number of states you want to enter in the map.\t";
    cin >> n;

    cout << "Enter state and then its population\n";

    for(int i = 0; i<n; i++) {
        cout << i+1<<"th entry\n";
        cin >> state;
        cin>>pop;

        population_map[state] = pop;
    }

    map<string,int> :: iterator itr;

    for(itr = population_map.begin(); itr != population_map.end(); itr++)

        cout << itr->first<< " : "<<itr->second<<"\n";
    
    cout << "Enter key you want to search\t";
    cin>>state;

    itr = population_map.find(state);

    if( itr != population_map.end()) {
        cout << "Record is present\n";
        cout << state<<" : "<<itr->second<<endl;
    }
    else    
        cout << "Record not found !!\n";
        
    cout << "Enter key you want to search\t";
    cin>>state;

    itr = population_map.find(state);

    if( itr != population_map.end()) {
        cout << "Record is present\n";
        cout << state<<" : "<<itr->second<<endl;
    }
    else    
        cout << "Record not found !!\n";
}