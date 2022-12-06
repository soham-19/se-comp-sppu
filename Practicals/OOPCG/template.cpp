#include <iostream>
using namespace std;

template <class T>
class Sort
{
private:
    T arr[100];
    int n;

    void getArray();

    void printArray();

    void selectionSort();

public:
    Sort()
    {
        this->getArray();
    }

    void wholeProcess();
};

template <class T>
void Sort<T>::wholeProcess()
{

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

        if (choice == 1)
        {
            Sort<int> objInt;
            objInt.wholeProcess();
        }
        else if (choice == 2)
        {
            Sort<char> objChar;
            objChar.wholeProcess();
        }
        else if (choice == 3)
        {
            Sort<float> objFloat;
            objFloat.wholeProcess();
        }
        else if (choice == 4)
        {
            Sort<double> objDouble;
            objDouble.wholeProcess();
        }
        else if (choice == 5)
        {
            Sort<string> objString;
            objString.wholeProcess();
        }
        else if (choice == 0)
        {
            cout << ".....Terminating.....";
            exit(0);
        }
        else
        {
            cout << "Invalid data type" << endl;
        }
    }

    return 0;
}


// OUTPUT  


// Enter choice.
// Selection for data-type :
//         1. int
//         2. char
//         3. float
//         4. double
//         5. string
// PRESS 0 TO EXIT

// 1
// Enter the number of elements    5
// Enter 1th element       6 7 -2 9 44
// Enter 2th element       Enter 3th element       Enter 4th element       Enter 5th element       Array created
// Before Sorting :  6 7 -2 9 44
// After Sorting :  -2 6 7 9 44

// Enter choice.
// Selection for data-type :
//         1. int
//         2. char
//         3. float
//         4. double
//         5. string
// PRESS 0 TO EXIT

// 2  
// Enter the number of elements    5
// Enter 1th element       r t y u i
// Enter 2th element       Enter 3th element       Enter 4th element       Enter 5th element       Array created
// Before Sorting :  r t y u i
// After Sorting :  i r t u y

// Enter choice.
// Selection for data-type :
//         1. int
//         2. char
//         3. float
//         4. double
//         5. string
// PRESS 0 TO EXIT

// 3
// Enter the number of elements    5
// Enter 1th element       4.5
// Enter 2th element       6.7
// Enter 3th element       8.9
// Enter 4th element       4.6
// Enter 5th element       -6.1
// Array created
// Before Sorting :  4.5 6.7 8.9 4.6 -6.1
// After Sorting :  -6.1 4.5 4.6 6.7 8.9

// Enter choice.
// Selection for data-type :
//         1. int
//         2. char
//         3. float
//         4. double
//         5. string
// PRESS 0 TO EXIT

// 4
// Enter the number of elements    5                        
// Enter 1th element       7.875
// Enter 2th element       9.765
// Enter 3th element       1.432
// Enter 4th element       6.542
// Enter 5th element       -9.876
// Array created
// Before Sorting :  7.875 9.765 1.432 6.542 -9.876
// After Sorting :  -9.876 1.432 6.542 7.875 9.765

// Enter choice.
// Selection for data-type :
//         1. int
//         2. char
//         3. float
//         4. double
//         5. string
// PRESS 0 TO EXIT

// 5
// Enter the number of elements    5
// Enter 1th element       qwe
// Enter 2th element       asd
// Enter 3th element       zxc
// Enter 4th element       aaa
// Enter 5th element       uhn
// Array created
// Before Sorting :  qwe asd zxc aaa uhn
// After Sorting :  aaa asd qwe uhn zxc

// Enter choice.
// Selection for data-type :
//         1. int
//         2. char
//         3. float
//         4. double
//         5. string
// PRESS 0 TO EXIT

// 0
// .....Terminating.....


