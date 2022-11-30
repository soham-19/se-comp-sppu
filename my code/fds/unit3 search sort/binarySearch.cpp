#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {

    int start = 0, end = n-1;

    do {
        int mid = (start + end)/2;

        if (arr[mid]==key)
            return mid;

        else if (arr[mid] > key)
            start = mid+1;
        else
            end = mid-1;

    }   
    while(start<=end);

    return -1;
}