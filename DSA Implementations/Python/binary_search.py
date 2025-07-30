def binary_search(arr,k):
    lb, ub, mid = 0, len(arr)-1, 0
    while lb <= ub:
        mid = (lb + ub) // 2
        if arr[mid] == k:
            return mid
        elif arr[mid] < k:
            lb = mid + 1
        else:
            ub = mid - 1
    return -1

n = int(input("Enter the number of elements in the array (Make sure it is sorted in ascending order) : "))
arr = []

for i in range(n):
    arr.append(int(input(f"Enter element {i+1} : ")))

k =  int(input("Enter the element to be searched : "))

binary_search_result = binary_search(arr, k)

if binary_search_result != -1:
    print(f"Element {k} found at index {binary_search_result}.")
else:
    print(f"Element {k} not found in the array.")
