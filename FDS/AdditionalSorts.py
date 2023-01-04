def merge(arr):

    if len(arr)<=1:
        return arr;
    
    mid = (len(arr)-1)//2

    left = arr[:mid+1]
    right = arr[mid+1:]

    left = merge(left)
    right = merge(right)

    merged = []

    r = 0
    l = 0

    while( r<len(right) and l<len(left)):

        if right[r] < left[l]:
            merged.append(right[r])
            r +=1
        else:
            merged.append(left[l])
            l += 1

    while r<len(right):
        merged.append(right[r])
        r +=1

    while l<len(left):
        merged.append(left[l])
        l += 1

    return merged



# Example usage
array = [3, 7, 4, 8, 6, 2, 1, 5]
print(array)
sorted_array = merge(array)
print(sorted_array)  # Output: [1, 2, 3, 4, 5, 6, 7, 8]