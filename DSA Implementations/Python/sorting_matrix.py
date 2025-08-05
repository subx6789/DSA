def sort_matrix(row, col, arr):
    for i in range(row):
        for j in range(col):
            for k in range(row):
                for l in range(col):
                    if arr[k][l] > arr[i][j]:
                        arr[i][j], arr[k][l] = arr[k][l], arr[i][j]

row = int(input("Enter the number of rows in the array : "))
col = int(input("Enter the number of columns in the array : "))
arr = []

print("Enter the elements of the array : ")
for _ in range(row):
    val = []
    for _ in range(col):
        val.append(int(input())) 
    arr.append(val)

sort_matrix(row, col, arr)

print("Sorted array : ")
print(*arr)