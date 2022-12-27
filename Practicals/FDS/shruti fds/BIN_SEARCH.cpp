#include<iostream>
#include<math.h>
using namespace std;

class Ss
{
    public:
    int ar[20];
    void sort(int[],int);
    void binS(int[],int);
    void get(int[],int);
};
void Ss:: get(int ar[20],int n)
{
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter ar["<<i<<"] = ";
        cin>>ar[i];
    }
}
void Ss::sort(int ar[20],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        if(ar[i]>ar[i+1])
        {
            temp=ar[i];
            ar[i]=ar[i+1];
            ar[i+1]=temp;
        }
    }
    cout<<"list is :{";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i];
        cout<<",";
    }
    cout<<"}"<<endl;
}
void Ss::binS(int ar[20],int n)
{
    int flag=0,low=0,high=n-1;
    int target;
    cout<<"Element to be searched : ";
    cin>>target;
    for(int i=0;i<n;i++)
    {
        float middle=(low+high)/2;
        int mid=floor(middle);
        if(ar[mid]==target)
        {
            int pos=mid;
            flag=1;
        }
        else if(ar[mid]>target)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(flag==1)
    {
        cout<<"Element found ";
    }
    else{
        cout<<"Element not found";
    }
}
int main()
{
    int n;
    cout<<"enter no.of elements in list : ";
    cin>>n;
    Ss s;
    s.get(s.ar,n);
    s.sort(s.ar,n);
    s.binS(s.ar,n);
   
    return 0;
}

