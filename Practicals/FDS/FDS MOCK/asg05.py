def get_array(n):
    print("Enter", n, "elements")
    arr = []
    for i in range(n):
        print("\tElement", i+1,"->",end=" ")
        arr.append(int(input()))
    print("Array inputted successfully !!")

    return arr

def selection_sort(arr, n):

    for i in range(n-1):
        minPos = i
        for j in range(i+1,n):
            if arr[minPos] > arr[j]:
                minPos = j
            
        arr[minPos], arr[i] = arr[i], arr[minPos]

        print("Pass : ", i+1, " :", arr)
            
def bubble_sort(arr, n):
    for i in range(n-1):
        swapped = False
        k = 0
        for j in range(n-i-1):

            if arr[j+1] < arr[j]:
                arr[j] , arr[j+1] = arr[j+1] , arr[j]
                swapped = True
            print("\tStep : ", k, " :", arr)
            k += 1
        if(swapped == False):
            break
        print("Pass : ", i+1, " :", arr)

        

print("No. of elements ?",end=" ")
n = int(input())

arr = get_array(n)

print("Before :", arr, end="\n\n")

# selection_sort(arr, len(arr))
bubble_sort(arr, len(arr))

print("After :", arr, end="\n\n")