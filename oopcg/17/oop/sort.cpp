#include<iostream>
using namespace std;

class select
{
private:int arr1[100];
	float arr2[100];
	int i,j,k,n;
public: 
	void getdata()
	{
	cout<<"Enter no. of elements: ";
	cin>>n;
	for(i=0;i<n;i++)
		{
		cout<<"Enter the "<<i+1<<" element of array: ";
		cin>>arr1[i];
		}
	}
	void display()
	{
	for(i=0;i<n;i++)
		{
		cout<<i+1<<" element of array is: "<<arr1[i]<<endl;
		}
	}
	
	void sorting()
	{
	for(i=0;i<n;i++)
		for(k=0;k<n;k++)
	{	if(arr1[i]<arr1[i+1])
		cout<<arr1[i];
		}
	}
};

int main()
{
select s;
s.getdata();
s.display();
s.sorting();
}



