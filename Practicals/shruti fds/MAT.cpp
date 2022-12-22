/*Write a Python program to compute following computation on matrix:
a) Addition of two matrices B) Subtraction of two matrices
c) Multiplication of two matrices d) Transpose of a matrix*/
//Name : Shruti Ware
//Div:B
//Roll.no.:68

#include <iostream>
using namespace std;

int main()
{
    int r, c, a[50][50], b[50][50], sum[50][50],sub[50][50] ,mul[50][50],i, j,k,transpose_a[50][50],transpose_b[50][50];

    cout << "Enter number of rows : ";
    cin >> r;

    cout << "Enter number of columns : ";
    cin >> c;

    cout << endl << "Enter elements of  matrix: " << endl;

    
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";			
           cin >> a[i][j];
       }

  
    cout << endl << "Enter elements of matrix: " << endl;
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }

    
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
            sum[i][j] = a[i][j] + b[i][j];				//sum of matrices

   
    cout << endl << "Sum of matrices is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << sum[i][j]<<" " ;
            if(j == c - 1)
                cout << endl;
        }

	for(i = 0; i < r; ++i)
		   for(j = 0; j < c; ++j)
		       sub[i][j] = a[i][j] - b[i][j];			//subtraction of matrices

   
    cout << endl << "Subtraction of matrices is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << sub[i][j]<<" " ;
            if(j == c - 1)
                cout << endl;
        }
        
	for(i = 0; i < r; ++i)
		   for(j = 0; j < c; ++j)
		       transpose_a[j][i] = a[i][j];  
		       
		cout<<endl<<"Transpose of matrix is 'a': "<<endl;
		for(i = 0; i < c; ++i)
		   for(j = 0; j < r; ++j)					//Transpose of matrix
		   {
		       cout << transpose_a[i][j]<<" " ;
		       if(j == r - 1)
		           cout << endl;
		   }
		   
	for(i = 0; i < r; ++i)
		   for(j = 0; j < c; ++j)
		       transpose_b[j][i] = b[i][j];  
		       
		cout<<endl<<"Transpose of matrix is 'b': "<<endl;
		for(i = 0; i < c; ++i)
		   for(j = 0; j < r; ++j)					//Transpose of matrix
		   {
		       cout << transpose_b[i][j]<<" " ;
		       if(j == r - 1)
		           cout << endl;
		   }        
        

int r1,c1,r2,c2;
do{
cout<<"Enter valid input"<<endl;
cout<<"Enter rows and column for 1st matrix : ";
cin>>r1>>c1;
cout<<"Enter rows and column for 2nd matrix : ";
cin>>r2>>c2;

}
while(c1!=r2);

 cout << endl << "Enter elements of  matrix: " << endl;

    
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";			
           cin >> a[i][j];
       }

  
    cout << endl << "Enter elements of matrix: " << endl;
    for(i = 0; i < r; ++i)
       for(j = 0; j < c; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }



for(i=0;i<r1;i++)
	for(j=0;j<c1;j++)
		for(k=0;k<r2;k++)
		{
		mul[i][j]+=a[i][k]*b[k][j];			//multiplication
		}
		
 cout << endl << "Multiplication of matrices is: " << endl;
    for(i = 0; i < r; ++i)
        for(j = 0; j < c; ++j)
        {
            cout << mul[i][j]<<" " ;
            if(j == c - 1)
                cout << endl;
      		}      		
    return 0;
    }
//OUTPUT
/*Enter number of rows : 2
Enter number of columns : 2

Enter elements of  matrix: 
Enter element a11 : 2
Enter element a12 : 3
Enter element a21 : 4
Enter element a22 : 5

Enter elements of matrix: 
Enter element b11 : 1
Enter element b12 : 3
Enter element b21 : 5
Enter element b22 : 7

Sum of matrices is: 
3 6 
9 12 

Subtraction of matrices is: 
1 0 
-1 -2 

Transpose of matrix is 'a': 
2 4 
3 5 

Transpose of matrix is 'b': 
1 5 
3 7 
Enter valid input
Enter rows and column for 1st matrix : 2
2
Enter rows and column for 2nd matrix : 2
2

Enter elements of  matrix: 
Enter element a11 : 3
Enter element a12 : 4
Enter element a21 : 5
Enter element a22 : 6

Enter elements of matrix: 
Enter element b11 : 6
Enter element b12 : 7
Enter element b21 : 8
Enter element b22 : 9

Multiplication of matrices is: 
50 57 
78 89 */
