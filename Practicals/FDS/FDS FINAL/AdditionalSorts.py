def merge_sort(array):
    # Base case: the array is already sorted if it has one element
    if len(array) <= 1:
        return array

    # Calculate the middle index
    mid = len(array) // 2

    # Divide the array into two halves
    left_half = array[:mid]
    right_half = array[mid:]

    # Recursively sort the two halves
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    # Merge the sorted halves
    merged_array = []
    left_index = 0
    right_index = 0
    while left_index < len(left_half) and right_index < len(right_half):
        if left_half[left_index] < right_half[right_index]:
            merged_array.append(left_half[left_index])
            left_index += 1
        else:
            merged_array.append(right_half[right_index])
            right_index += 1

    # Copy any remaining elements of left_half[]
    while left_index < len(left_half):
        merged_array.append(left_half[left_index])
        left_index += 1

    # Copy any remaining elements of right_half[]
    while right_index < len(right_half):
        merged_array.append(right_half[right_index])
        right_index += 1
    print(merged_array)
    return merged_array

# Example usage
array = [3, 7, 4, 8, 6, 2, 1, 5]
print(array)
sorted_array = merge_sort(array)
print(sorted_array)  # Output: [1, 2, 3, 4, 5, 6, 7, 8]