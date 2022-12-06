#include <iostream>
using namespace std;

    void p(int a[], int n){
        cout<<"array is :\n";
        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<endl;
        
    }
main(){

    int arr[100];
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "pos"<<endl;
    int pos;
    cin>>pos;
    int data;
    cout<<"data"<<endl;
    cin>>data;
    p(arr,n);
    for(int i=n-1; i>=pos-1; i--)
        arr[i+1]=arr[i];
    n++;
    arr[pos-1]=data;
    p(arr,n);
    cin>>pos;
    p(arr,n);
    for(int i=pos-1; i<n-1; i++)
        arr[i]=arr[i+1];
    n--;
    p(arr,n);



}