#include<iostream>
#include<math.h>
using namespace std;
class Lin_S
{
	public:
		int ar[10];
		void get(int[],int);
		void show(int[],int);
		void linS(int[],int);
		
};
void Lin_S::get(int ar[10],int ele)
{
	for(int i=0;i<ele;i++)
	{
		cout<<"ar["<<i<<"] =";
		cin>>ar[i];
	}
}
void Lin_S::show(int ar[10],int ele)
{
	cout<<"Array is:{";
	for(int i=0;i<ele;i++)
	{
		cout<<ar[i];
		cout<<",";	
	}
	cout<<"}"<<endl;
}
void Lin_S::linS(int ar[10],int ele)
{
	int n,flag=0;
	cout<<"Enter no. to be searched:";
	cin>>n;
	for(int i=0;i<ele;i++)
	{
		if(ar[i]==n)
		{
			int pos=i;
			flag=1;
		}
		
	}
		if(flag==1)
		{
			cout<<"Element found"<<endl;
		}
		else
		{
			cout<<"Element not in array"<<endl;	
		}
	
}
int main()
{
	int ele;
	cout<<"Enter no. of elements in array:";
	cin>>ele;
	Lin_S a;
	a.get(a.ar,ele);
	a.show(a.ar,ele);
	a.linS(a.ar,ele);
	return 0;
}
	
