#include <iostream>
using namespace std;
#define M 5

template <class T>
class Sort
{
    T arr[M];
    int n;

    void getArr()
    {
        cout << "Enter number of elements : ";
        cin >> this->n;

        cout << "Enter " << n << " elements :\n";
        for(int i=0; i<n; i++)
        {
            cout << "\t-> Element " << i+1 << " : ";
            cin >> arr[i];
        }
    }
    void printArr()
    {
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << endl;
        
    }
    void selecionSort()
    {
        for (int i=0; i<n; i++)
        {
            int mP = i;
            for(int j=i+1; j<n; j++)
            {
                if (arr[j] < arr[mP])
                    mP = j;
            }
                swap(arr[mP], arr[i]);
        }
    }
    
    public:

        Sort()
        {
            this->getArr();
            cout << "Before sorting ";
            this->printArr();
            this->selecionSort();
            cout << "After sorthing ";
            this->printArr();
        }

        void get();
};

int main()
{
    while(true)
    {
        cout << "   M A I N  M E N U\n";
        cout << "1-int\n";
        cout << "2-char\n";
        cout << "3-float\n";
        cout << "4-double\n";
        cout << "5-string\n";

        cout << "\n\t-> Enter your choice : ";
        int ch;
        cin >> ch;

        if(ch==1)
            Sort<int> obj;
        else if(ch==2)
            Sort <char> obj;
        else if(ch==3)
            Sort <float> obj;
        else if(ch==4)
            Sort<double> obj;
        else if(ch==5)
            Sort<string>obj;
        else if (ch==0)
            {   cout << "Terminating\n\n";  exit(0);    }
        else
            cout << "Try Again!!\n";
    }
}
