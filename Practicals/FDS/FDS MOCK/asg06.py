'''Write a Python program to store second year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
Insertion sort
Shell Sort and display top five scores'''


def insertionSort(arr, n):

    for i in range(1,n):
        temp = arr[i]

        j = i-1

        while ( j>=0 and arr[j] > temp):
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = temp


data=[]
print("Enter the size of array: ")
n=int(input())
for i in range (n):
    print("Element" , i+1, "->", end=" ")
    m=int(input())
    data.append(m)
    
print(data)
insertionSort(data, len(data))
print('Sorted Array using insertion sort:')
print(data)

# shellSort(data,n)
# print('Sorted Array using shell sort:')
# print(data)


for i in range (5):
    print(data[i])


    
  
