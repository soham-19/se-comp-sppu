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

    for (int i = 0; i < n; i++)
    {

        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            cout << "best " << i << endl;
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
    for (int i=1; i<n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;

    }
}

void shellSort(int a[], int n){

    for( int gap = n/2; gap > 0; gap = gap/2)
    {
        for (int j = gap; j<n; j++)
        {
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if( a[i+gap] > a[i])
                    break;
                else
                    swap( a[i+gap], a[i] );
            }
        }
    }
}

int partition(int a[], int lb, int ub){

    int pivot = a[lb];
    int start = lb, end = ub;

    
    while(start < end){

        while(a[start] <= pivot)
        start++;
    
        while(a[end] > pivot)
            end--;
    
        if (start < end)
            swap(a[start],a[end]);

    }

    swap(a[end], a[lb]);

    return end;
    
}

void QuickSort(int a[], int lb, int ub){
    int loc;
    if(lb < ub)
    loc = partition(a,lb,ub);
    print(a,5);
    QuickSort(a,lb,loc-1);
    QuickSort(a,loc+1,ub);
}
int main()
{

    int a[] = {5, 4, 1, 3, 2};
    print(a, 5);
    // selectionSort(a, 5);
    // insertionSort(a, 5);
    QuickSort(a,0,4);
    print(a, 5);
    return 0;
}