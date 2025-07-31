def selection_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        min_index = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]

n = int(input("Enter the number of elements in the array : "))
arr = []

print("Enter the elements of the array : ")
for _ in range(n):
    arr.append(int(input()))

selection_sort(arr)

print("Sorted array : ")
print(*arr)
