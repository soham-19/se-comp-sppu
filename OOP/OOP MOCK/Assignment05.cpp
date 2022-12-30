#include<iostream>
using namespace std;
#define M 5
template <class T>
class Sort{
    T arr[M];
    int n;

    public:

    Sort(){
        getArr();
        cout<< "Before sorting ";
        printArr();
        SelectionSort();
        cout<< "After sorting ";
        printArr();
    }

    void getArr(){
        cout << "Enter size : ";
        cin >>n;

        cout << "Enter elements :\n";
        for(int i=0; i<n; i++){
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
        cout << "Array stored successfully!\n";
    }

    void printArr(){
        cout << " array is : ";

        for (int i=0; i<n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void SelectionSort(){

        cout << "Performing selection sort...\n";
        for(int i=0; i<n-1; i++){

            int minPos = i;

            for(int j=i+1; j<n;j++){
                if (arr[j] < arr[minPos])
                    minPos = j;
            }
            swap(arr[i], arr[minPos]);
        }
        cout << "Selection sort performed successfully!!\n";
    }
};

int main(int argc, char const *argv[])
{
    int ch;

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
            cin >> ch;

        if(ch==0){
            cout << "TERMINATING\n\n";
            exit(0);
        }
        else if(ch==1)
            Sort<int> obj;
        
        else if(ch==2)
            Sort<char> obj;
        
        else if(ch==3)
            Sort<float> obj;
        
        else if(ch==4)
            Sort<double> obj;
        
        else if(ch==5)
            Sort<string> obj;
        
        else 
            cout << "INVALID CHOICE!!\nLE'S TRY AGAIN\n\n";
        
    }

    return 0;
}
