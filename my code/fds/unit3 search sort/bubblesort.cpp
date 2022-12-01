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
int main()
{

    int a[] = {5, 4, 1, 3, 2};
    print(a, 5);
    bubbleSort(a, 5);
    print(a, 5);
    return 0;
}