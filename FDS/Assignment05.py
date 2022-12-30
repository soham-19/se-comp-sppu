# selection sort

def selectionSort(arr,n):
    for i in range(n-1):
        minP = i

        for j in range(i+1,n):
            if arr[j] < arr[minP]:
                minP = j
        arr[minP], arr[i] = arr[i], arr[minP]

def bubbleSort(arr,n):
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
arr = [0,6,5,3,2,1,8,9,10]
print(arr)
bubbleSort(arr, len(arr))
print(arr)


''''
OUTPUT:
Enter the number of students: 4
89
90
86
87

 Marks before sorting:  [89, 90, 86, 87]

 1.Selection sort 
 2. Bubble sort
 3.Top five scores

 Enter your choice: 1

 After sorting:
[86, 87, 89, 90]

Enter your choice: 2

 After sorting:
[86, 87, 89, 90]

Enter your choice: 3
[90, 89, 87, 86]
'''



    