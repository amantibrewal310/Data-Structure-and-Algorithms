row = int(input("Enter number of rows: "))
column = int(input("Enter number of columns: "))

matrix = []
print("Enter the value in row: ")

for i in range(row):
    a = []
    for j in range(column):
        a.append(int(input()))
    matrix.append(a)

for i in range(row):
    for j in range(column):
        print(matrix[i][j], end=" ")
    print()