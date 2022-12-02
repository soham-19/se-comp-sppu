#include <iostream>
using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int a[], int n)
{

    for (int pass = 0; pass < n; pass++)
    {

        bool swapped = false;

        for (int index = 0; index < n - 1 - pass; index++)
        {
            if (a[index] > a[index + 1])
            {
                swap(a[index], a[index + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            cout << "best " << pass << endl;
            return;
        }
    }
}

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        int minPos = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minPos])
                minPos = j;
        }

        swap(arr[minPos], arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++){

        int temp = arr[i];
        int j = i - 1;

        while( j >= 0 ) {

            if (arr[j] < temp)

                arr[j+1] = arr[j];

            else
                break;

            j--;
        }

        arr[j+1] = temp;
    }
}
int main()
{

    int a[] = {5, 4, 1, 3, 2};
    print(a, 5);
    insertionSort(a, 5);
    print(a, 5);
    return 0;
}