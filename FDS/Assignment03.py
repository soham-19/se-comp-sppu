def getMat():
    print("Rows :",end=" ")
    r = int(input())

    print("Cols :",end=" ")
    c = int(input())
      
    mat = []

    for i in range(r):
        row = []
        for j in range(c):
            print("Element", i,j,end="-> ")
            x = int(input())
            row.append(x)
        mat.append(row)

    print("Matrix stored successfully!\n")
    return mat
def printMat(mat):
    for i in mat:
        print("\t",i)
    print()
    print()

def add(mat1, mat2):

    if len(mat1)!=len(mat2) or len(mat1[0])!=len(mat2[0]):
        print("These matrices can't be added")
        return -1

    sum = []

    for i in range(len(mat1)):
        row = []
        for j in range(len(mat1[0])):
            row.append(mat1[i][j] + mat2[i][j])
        sum.append(row)
    
    # print("Sum matrix calculated successfully!\n")
    return sum
    
def sub(mat1, mat2):

    if len(mat1)!=len(mat2) or len(mat1[0])!=len(mat2[0]):
        print("These matrices can't be subtracted")
        return -1

    diff = []

    for i in range(len(mat1)):
        row = []
        for j in range(len(mat1[0])):
            row.append(mat1[i][j] - mat2[i][j])
        diff.append(row)
    
    # print("Difference matrix calculated successfully!\n")
    return diff

def mult(mat1, mat2):

    if len(mat1)!=len(mat2[0]):
        print("These matrices can't be multiplied")
        return -1
    
    prod = []

    for i in range(len(mat1)):
        row = []
        for j in range(len(mat2[0])):
            sum = 0
            for k in range(len(mat2)):
                sum += mat1[i][k] * mat2[k][j]
            row.append(sum)
        prod.append(row)

    # print("Product matrix calculated successfully!\n")
    return prod

def transpose(mat):

    trans = []
    # initializing transpose matrix with proper size and zero's
    for i in range(len(mat[0])):
        row = []
        for j in range(len(mat)):
            row.append(0)
        trans.append(row)

    # performing transpose
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            trans[i][j] = mat[j][i]

    print("Transpose matrix calculated successfully!\n")
    return trans

# main

mat1 = getMat()
mat2 = getMat()
print("Matrix 1 is :")
printMat(mat1)
print("Matrix 2 is :")
printMat(mat2)

sumMatrix = []
if add(mat1, mat2) != -1:
    sumMatrix = add(mat1,mat2)
else:
    print("Sum matrix calculated successfully!\n")

diffMatrix = []
if sub(mat1, mat2) != -1:
    diffMatrix = sub(mat1,mat2)
else:
    print("Difference matrix calculated successfully!\n")

prodMat = []
if mult(mat1, mat2) != -1:
    prodMat = mult(mat1,mat2)
else:
    print("Product matrix calculated successfully!\n")

trans1 = transpose(mat1)
trans2 = transpose(mat2)

print("Sum Matrix is :")
printMat(sumMatrix)
print("Difference Matrix is :")

printMat(diffMatrix)
print("Product Matrix is :")
printMat(prodMat)

print("Transpose for Matrix 1 is :")
printMat(trans1)

print("Transpose for Matrix 2 is :")
printMat(trans2)

'''OUTPUT:
 Enter number of rows in the matrix: 2

 Enter number of columns in the matrix: 2

 Enter elements for first matrix, A: 

Enter A[0][0]: 1
Enter A[0][1]: 2
Enter A[1][0]: 3
Enter A[1][1]: 4

 Enter elements for second matrix, B:

Enter B[0][0]: 1
Enter B[0][1]: 2
Enter B[1][0]: 3
Enter B[1][1]: 4

 The matrix A is:

1 2
3 4

 The matrix B is:

1 2
3 4
------MENU------

 1.Addition
 2.Substraction
 3.Multiplication
 4.Transpose
 5.Exit
1

ADDITION

2 4
6 8
------MENU------

 1.Addition
 2.Substraction
 3.Multiplication
 4.Transpose
 5.Exit
2

SUBSTRACTION

0 0
0 0
------MENU------

 1.Addition
 2.Substraction
 3.Multiplication
 4.Transpose
 5.Exit
3

MULTIPLICATION

7 10
15 22
------MENU------

 1.Addition
 2.Substraction
 3.Multiplication
 4.Transpose
 5.Exit
4

TRANSPOSE


 Transpose of matrix A is:

1 3
2 4

 Transpose of matrix B is:

1 3
2 4
------MENU------

 1.Addition
 2.Substraction
 3.Multiplication
 4.Transpose
 5.Exit
5
'''








