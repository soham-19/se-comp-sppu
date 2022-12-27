'''
    Write a Python program to compute following computation on matrix:
        a)  Addition of two matrices
        b) Subtraction of two matrices
        c) Multiplication of two matrices
        d) Transpose of a matrix
'''

def getMat(matrix):
    
    print("Enter no of rows : ")
    r = int(input())

    print("Enter no of columns : ")
    c = int(input())

    print("Enter elements row-wise")

    for i in range(r):
        row = []
        for j in range(c):
            print("index-> ",i,",",j," :",sep="",end=" ")
            x = int(input())
            row.append(x)
        matrix.append(row)

    print()
    print()

def printMat(mat):
    for i in range(len(mat)):
        print('\t')
        for j in range(len(mat[0])):
            print(mat[i][j], end=" ")
        print()
    print()
    print()

def add(mat1, mat2):
    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        print("Addition can't be performed on these martices")
        return
    
    addition = []

    for i in range(len(mat1)):
        row = []

        for j in range(len(mat1[0])):
            row.append(mat1[i][j]+mat2[i][j])
        addition.append(row)

    print("Addition Matrix is : ")

    printMat(addition)

def sub(mat1, mat2):

    if len(mat1) != len(mat2) or len(mat1[0]) != len(mat2[0]):
        print("Subtraction can't be performed on these martices")
        return
    
    subtraction = []

    for i in range(len(mat1)):
        row = []

        for j in range(len(mat1[0])):
            row.append(mat1[i][j]-mat2[i][j])

        subtraction.append(row)

    print("Subtraction Matrix is : ")

    printMat(subtraction)
    
def mult(mat1,mat2):

    if len(mat1[0]) != len(mat2):
        print("No")
        return
    
    result = []

    for i in range(len(mat1)):
        row = []
        for j in range(len(mat2[0])):
            row.append(0)
        result.append(row)

    for i in range(len(mat1)):
        for j in range(len(mat2[0])):
            for k in range(len(mat2)):
                result[i][j] += mat1[i][k] * mat2[k][j]

    print("Multiplication Matrix is : ")
    printMat(result)

def transpose(mat):
    trans = []

    for i in range(len(mat[0])):
        r = []
        for j in range(len(mat)):
            r.append(0)
        trans.append(r)
    
    for i in range(len(trans)):
        for j in range(len(trans[0])):
            trans[i][j] = mat[j][i]

    print("Transpose Matrix is : ")
    printMat(trans)

mat1 = []
mat2 = []


getMat(mat1)
getMat(mat2)
printMat(mat1)
printMat(mat2)
add(mat1, mat2)
sub(mat1, mat2)

mult(mat1,mat2)
transpose(mat1)
transpose(mat2)