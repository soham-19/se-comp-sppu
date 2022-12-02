#include <iostream>
using namespace std;

template <class T>
class Sort
{
private:
    T arr[100];
    int n;

public:
    Sort()
    {
        this->getArray();
    }
    void getArray();

    void printArray();

    void selectionSort();

    void wholeProcess();
};

template <class T>
void Sort<T>::wholeProcess() {

    cout << "Before Sorting :  ";
    this->printArray();

    this->selectionSort();

    cout << "After Sorting :  ";
    this->printArray();
}

template <class T>
void Sort<T>::getArray()
{

    cout << "Enter the number of elements\t";
    cin >> this->n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th element\t";
        cin >> arr[i];
    }
    cout << "Array created" << endl;
}

template <class T>
void Sort<T>::printArray()
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
template <class T>
void Sort<T>::selectionSort()
{

    for (int i = 0; i < n - 1; i++)
    {

        int minPositionIndex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minPositionIndex])

                minPositionIndex = j;
        }
        swap(arr[i], arr[minPositionIndex]);
    }
}

int main()
{

    while (true)
    {
        cout << endl
             << "Enter choice." << endl
             << "Selection for data-type :" << endl
             << "\t1. int" << endl
             << "\t2. char" << endl
             << "\t3. float" << endl
             << "\t4. double" << endl
             << "\t5. string" << endl
             << "PRESS 0 TO EXIT" << endl
             << endl;
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Sort<int> objInt;
            objInt.wholeProcess();
            
            break;
        case 2:
            Sort<char> objChar;
            objChar.wholeProcess();
            break;
        case 3:
            Sort<float> objFloat;
            objFloat.wholeProcess();
            break;
        case 4:
            Sort<double> objDouble;
            objDouble.wholeProcess();
            break;
        case 5:
            Sort<string> objString;
            objString.wholeProcess();
            break;
        case 0:
            cout << ".....Terminating.....";
            exit(0);
            break;
        
        default:
            cout << "Invalid data type"<<endl;
            break;
        }
    }

    return 0;
}