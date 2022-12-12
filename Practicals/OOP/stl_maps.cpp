#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;
int main()
{
    map<string, int> populationMap;
    string state_name, name;
    int number, n;
    cout << "\n How many states  you want to enter?";
    cin >> n;
    cout << "Enter the name of state and population \n";
    for (int i = 0; i < n; i++)
    {
        cin >> name >> number;
        populationMap[name] = number;
    }
    populationMap.insert(pair<string, int>("Maharashtra", 114200000));
    map<string, int>::iterator iter;
    cout << "Population of state\n";
    cout << "\n Size of population Map:" << populationMap.size() << "\n";
    for (iter = populationMap.begin(); iter != populationMap.end(); iter++)
    {
        cout << iter->first << ":" << iter->second << "\n";
    }
    cout << "\n Enter name of the state :";
    cin >> state_name;
    iter = populationMap.find(state_name);
    if (iter != populationMap.end())
        cout << state_name << " 's population is " << iter->second;
    else
        cout << "Key is not populationMap"
             << "\n";
    populationMap.clear();
}