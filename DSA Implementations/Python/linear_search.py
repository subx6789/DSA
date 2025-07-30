def linear_search(arr,k):
    for i in range(len(arr)):
        if arr[i] == k:
            return i
    return -1

n = int(input("Enter the number of elements in the array : "))
arr = []

for i in range(n):
    arr.append(int(input(f"Enter element {i+1} : ")))

k =  int(input("Enter the element to be searched : "))

linear_search_result = linear_search(arr, k)

if linear_search_result != -1:
    print(f"Element {k} found at index {linear_search_result}.")
else:
    print(f"Element {k} not found in the array.")
