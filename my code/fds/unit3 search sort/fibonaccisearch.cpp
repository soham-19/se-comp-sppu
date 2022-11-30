#include <iostream>
using namespace std;
int fib(int n)
{
    if (n == 1 || n == 0)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int fibonacciSearch(int arr[], int n, int key)
{
    int k = 0;
    int f_Of_k = 0;

    while (1)
    {
        f_Of_k = fib(k);
        if (f_Of_k >= n)
        {
            break;
        }
        k++;
    }

    int offset = -1;

    int i = min(offset + fib(k - 2), n - 1);

    while (1)
    {
        if (f_Of_k == -1)
            return -1;
        if (key == arr[i])
            return i;
        else if (key > arr[i])
        {
            k--;
            offset = i;
        }
        else
        {
            k -= 2;
        }
    }
}
int main()
{
    int a [] = {1,2,3,4,5,6,7};

    cout << fibonacciSearch(a,6,7);
}