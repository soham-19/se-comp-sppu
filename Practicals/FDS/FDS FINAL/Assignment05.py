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