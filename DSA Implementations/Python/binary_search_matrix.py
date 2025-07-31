def binary_search(arr,rows,cols,k):
    
    lb,ub,mid = 0,(rows*cols)-1,0
    
    while lb<=ub:
        
        mid = (lb+ub)//2
        mid_row = mid//cols
        mid_col=mid%cols
        
        if arr[mid_row][mid_col] == k:
            return (mid_row,mid_col)
        elif arr[mid_row][mid_col]<k:
            lb=mid+1
        else:
            ub=mid-1
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

binary_search_result = binary_search(arr,rows,cols, k)

if binary_search_result != -1:
    print(f"Element {k} found at index {binary_search_result}.")
else:
    print(f"Element {k} not found in the array.")
