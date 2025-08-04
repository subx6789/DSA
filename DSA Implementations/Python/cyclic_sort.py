def cyclic_sort(arr):
    i = 0
    while i < len(arr):
        correct_index = arr[i] - 1
        if arr[i] != arr[correct_index]:
            arr[i], arr[correct_index] = arr[correct_index], arr[i]
        else:
            i += 1

n = int(input("Enter the number of elements in the array : "))
arr = []

print("Enter the elements of the array : ")
for _ in range(n):
    arr.append(int(input()))

cyclic_sort(arr)

print("Sorted array : ")
print(*arr)
