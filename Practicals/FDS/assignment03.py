
'''Write a Python program to compute following computation on matrix:
a)  Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix'''


##Name : Soham Arun Kulkarni
##RollNo.:68
##Div:B

def getMat(mat,r,c):
    print("Enter the elements row-wise: ")
    for i in range(r):
        m=[]
        for j in range(c):
            ele=int(input())
            m.append(ele)
        mat.append(m)

def printMat (mat,r,c):
    print("MATRIX :")
    for i in range(r):
        for j in range(c):
            print(mat[i][j] , end=" ")
        print()
        print()

def add(matrix1,r1,c1,matrix2,r2,c2):
    if(r1==r2 and c1==c2):
        add=[]
        for i in range (r1):
            r=[]
            for j in range(c1):
                a=matrix1[i][j] + matrix2[i][j]
                r.append(a)
            add.append(r)
        printMat(add, r1, c1)
    else:
        print("Addition cannot be performed")
            
def sub(matrix1,r1,c1,matrix2,r2,c2):
    if(r1==r2 and c1==c2):
        sub=[]
        for i in range (r1):
            r=[]
            for j in range(c1):
                a=matrix1[i][j] - matrix2[i][j]
                r.append(a)
            sub.append(r)
        printMat(sub, r1, c1)
    else:
        print("Subtraction cannot be performed")


def multi(matrix1,r1,c1,matrix2,r2,c2):
    if(r2==c1):
        multi=[]
        for i in range(r1):
            list = []
            for j in range(c2):
                list.append(0)
            multi.append(list)

        for i in range(r1):
             for j in range(c1):
                 for k in range(c1):
                    multi[i][j] += matrix1[i][k] * matrix2[k][j]
            
        printMat(multi, r1, c2)
                
    else:
        print("Multiplication cannot be performed")
            
def transpose(r1,c1):
    trans=[]
    for i in range (r1):
        r=[]
        for j in range(c1):
            r.append(0)
        trans.append(r)
    for i in range (r1):
        for j in range(c1):
            trans[i][j]=matrix2[j][i]
    printMat(trans, r1, c1)


#                                                           main

print("Information for matrix1")
r1=int(input("Enter the number of rows for matrix1 :\t"))
c1=int(input("Enter the number of columns for matrix1 :\t"))

matrix1=[]
getMat(matrix1, r1, c1)

print("Information for matrix2")
r2=int(input("Enter the number of rows for matrix2 :\t"))
c2=int(input("Enter the number of columns for matrix2 :\t"))

matrix2=[]
getMat(matrix2, r2, c2)

printMat(matrix1, r1, c1)
printMat(matrix2, r2, c2)

            
            
while(1):

    print("Enter your choice: ")
    print("1. Addition \n2. Subtraction \n3. Multiplication \n4. Transpose \n0. Exit")
    ch=int(input("Choice :\t"))
    
    if(ch==1):
       add(matrix1,r1,c1,matrix2,r2,c2)       
    elif(ch==2):
        sub(matrix1,r1,c1,matrix2,r2,c2)
    elif(ch==3):
        multi(matrix1,r1,c1,matrix2,r2,c2)    
    elif(ch==4):
        print("Transpose of first matrix is:")
        transpose(r1,c1)
        print("Transpose of second matrix is:")
        transpose(r2,c2)
    elif(ch==0):
        exit(0)