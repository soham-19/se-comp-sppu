#include <iostream>
#include <vector>
using namespace std;
void getArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void printArr(int a[], int n)
{
    cout << "Array is :   ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << endl;
}

void merge(int a[], int n, int b[], int m, int mergArr[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < n) && (j < m)){
        
        if( a[i] < b[j] )
            mergArr[k++] = a[i++];
        
        else
            mergArr[k++] = b[j++];

    }

    while(i<n)
        mergArr[k++]  = a[i++];

    while(j<m)
        mergArr[k++]  = b[j++];
    
}
int main()
{

    int arr1[10];
    int arr2[10];
    int mergArr[100];

    getArr(arr1, 4);
    getArr(arr2, 3);

    printArr(arr1, 4);
    printArr(arr2, 3);

    merge(arr2, 3, arr1, 4, mergArr);

    printArr(mergArr, 7);

    return 0;
}