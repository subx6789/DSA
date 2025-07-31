def linear_search(arr,k):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == k:
                return (i,j)
    return -1

rows = int(input("Enter the number of rows in the array : "))
cols = int(input("Enter the number of columns in the array : "))
arr = []

for i in range(rows):
    row=[]
    for j in range(cols):
        row.append(int(input(f"Enter element ({i},{j}) : ")))
    arr.append(row)

k =  int(input("Enter the element to be searched : "))

linear_search_result = linear_search(arr, k)

if linear_search_result != -1:
    print(f"Element {k} found at index {linear_search_result}.")
else:
    print(f"Element {k} not found in the array.")
