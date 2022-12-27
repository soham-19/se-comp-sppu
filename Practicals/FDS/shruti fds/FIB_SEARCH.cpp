#include<iostream>
#include<math.h>
using namespace std;
class fibS
{
    public:
    int ar[20];
    void sort(int[],int);
    void fib(int[],int);
    void get(int[],int);

};
void fibS::get(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Enter ar["<<i<<"] = ";
        cin>>ar[i];
    }
}
void fibS::sort(int ar[],int n)
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
    cout<<"}\n";
}
void fibS::fib(int ar[],int n)
{
    int fibAr[20];
    int flag,f1,f2,k,mid,target;
    cout<<"Enter element to be searched : ";
    cin>>target;
    for(int i=2;i<n;i++)
    {
        fibAr[0]=0;
        fibAr[1]=1;
        fibAr[i]=fibAr[i-2]+fibAr[i-1];
    }
    cout<<"Fibonacci series is : ";
    for(int i=0;i<n;i++)
    {
        cout<<"fibAr["<<i<<"]="<<fibAr[i]<<" ";
    }
    for (int i = 0; i < n; i++)
    {
        if(n<=fibAr[i])
        {
            k=i;
            break;
        }
    }
    f1=fibAr[k-2];
    f2=fibAr[k-3];
    mid=n-fibAr[1]+1;
    for(int i=0;i<n;i++)
    {
        if(ar[mid]==target)
        {
            cout<<"Element "<<target<<" found at "<<mid<<"\n";
            break;
        }
        if(target>ar[mid] && f1==1)
        {
            cout<<"Unsuccessful search";
            exit;
        }
        else if(target>ar[mid])
        {
            mid=mid+f2;
            f1=fibAr[k-4];
            f2=fibAr[k-5];
            if(target==fibAr[mid])
            {
                cout<<"Element "<<target<<" found at "<<mid<<"\n";
                break;
            }
            
        }
        if(target<ar[mid] && f2==0)
        {
            cout<<"Unsuccessful search";
            exit;
        }
        else if(target<ar[mid])
        {
            mid=mid-f2;
            f1=fibAr[k-3];
            f2=fibAr[k-4];
            if(target==fibAr[mid])
            {
                cout<<"Element "<<target<<" found at "<<mid<<"\n";
                break;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter no of elements in array: ";
    cin>>n;
    fibS s;
    s.get(s.ar,n);
    s.sort(s.ar,n);
    s.fib(s.ar,n);
    return 0;
}


    

