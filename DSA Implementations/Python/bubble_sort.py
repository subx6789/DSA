def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        swapped = False  

        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped:
            break

n = int(input("Enter the number of elements in the array : "))
arr = []

print("Enter the elements of the array : ")
for _ in range(n):
    arr.append(int(input()))

bubble_sort(arr)

print("Sorted array : ")
print(*arr)
