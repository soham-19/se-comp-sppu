'''
    Write a Python program to compute following computation on matrix:
        a)  Addition of two matrices
        b) Subtraction of two matrices
        c) Multiplication of two matrices
        d) Transpose of a matrix
'''

def getMat():

    matrix = []

    print("Rows ?", end=" ")
    r = int(input())
    
    print("Cols ?", end=" ")
    c = int(input())
    print("Enter elements row-wise")
    for i in range(r):
        row = []
        for j in range(c):
            print("\t->", end = " ")
            x = int(input())
            row.append(x)
        matrix.append(row)
    
    return matrix

def printMat(mat):

    for i in range(len(mat)):
        print(end="\t")
        print(mat[i])
        print()
    
    print()

def add(mat1, mat2):
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        print("These matrices can't be added !")
        return
    
    sum = []

    for i in range(len(mat1)):
        row = []
        for j in range(len(mat1[0])):
            row.append(mat1[i][j] + mat2[i][j])
        sum.append(row)

    print("Sum Matrix is :")
    printMat(sum)

def sub(mat1, mat2):
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        print("These matrices can't be subtracted !")
        return
    
    diff = []

    for i in range(len(mat1)):
        row = []
        for j in range(len(mat1[0])):
            row.append(mat1[i][j] - mat2[i][j])
        diff.append(row)

    print("Difference Matrix is :")
    printMat(diff)

def mult(mat1, mat2):
    if len(mat1[0]) != len(mat2):
        print("These matrices can't be multiplied !")
        return

    product = []

    for i in range(len(mat1)):
        row = []
        for j in range(len(mat2[0])):
            sum = int(0)
            for k in range(len(mat2)):
                sum += mat1[i][k] * mat2[k][j]
            row.append(sum)
        product.append(row)
    
    print("Product Matrix is :")
    printMat(product)

def setTranspose(mat):
    
    trans = []
    for i in range(len(mat[0])):
        row = []
        for j in range(len(mat)):
            row.append(int(0))
        trans.append(row)
    
    return trans

def transpose(mat):
    trans = setTranspose(mat)

    for i in range(len(mat)):
        for j in range(len(mat[0])):
            trans[i][j] = mat[j][i]

    
    print("Transpose Matrix is :")
    printMat(trans)

matrix1 = getMat()
matrix2 = getMat()
print("Matrix A is :")
printMat(matrix1)
print("Matrix B is :")
printMat(matrix2)
add(matrix1, matrix2)
sub(matrix1, matrix2)
mult(matrix1, matrix2)
print("For A",end=" ")
transpose(matrix1)
print("For B",end=" ")
transpose(matrix2)

