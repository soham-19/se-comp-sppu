
'''Write a Python program to store second year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using
Insertion sort
Shell Sort and display top five scores'''


#Name : Soham Arun Kulkarni
#RollNo.:31
#Div:B

def shellSort(data, n):

    # Rearrange elements at each n/2, n/4, n/8, ... intervals
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = data[i]
            j = i
            while j >= gap and data[j - gap] > temp:
                data[j] = data[j - gap]
                j -= gap

            data[j] = temp
        gap //= 2




def insertionSort(array):

    for i in range(1, len(array)):
        key = array[i]
        j = i- 1
        
        # Compare key with each element on the left of it until an element smaller than it is found
        # For descending order, change key<array[j] to key>array[j].        
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
        
        # Place key at after the element just smaller than it.
        array[j + 1] = key



data=[]
print("Enter the size of array: ")
n=int(input())
for i in range (n):
    print("Enter the elements ",i+1,"=")
    m=int(input())
    data.append(m)
    
print(data)
insertionSort(data)
print('Sorted Array using insertion sort:')
print(data)

shellSort(data,n)
print('Sorted Array using shell sort:')
print(data)

print("Toppers:")
for i in range (5):
    print(i," : ", data[i])