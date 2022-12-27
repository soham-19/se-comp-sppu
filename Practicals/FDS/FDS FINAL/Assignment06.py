def insertionSort(arr, n):

    for i in range(1,n):
        temp = arr[i]
        j = i-1

        while j>=0 and arr[j] > temp:
                
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = temp 

        print("\tPass ", i, arr)

arr = [0, 6, 5, 3, 2, 1, 8, 9, 10]

print(arr)
insertionSort(arr, len(arr))
print(arr)