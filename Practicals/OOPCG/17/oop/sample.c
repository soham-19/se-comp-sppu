#include <stdio.h>
void main()
{
int arr[] = {10,20,30,40,50,60,70,80,90,100};
int mid = (begin+end)/2;
int k = 80;
if (k>80)
{
begin = mid + 1;
for(i=0;i<=end;i++)
   {  
   if (arr[i]==k)
   {
     printf("\n element is found at:%d",i);
     break;
   }
   else{
        printf("element is not found try next element");
   }
   }

}






}
