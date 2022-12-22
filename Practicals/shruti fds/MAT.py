m1 = []
m = []
m2 = []
res = [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0,0]]
print("Welcome all in assignment no:03 from Group A")
print("For Matrix operation we require some input from you Please.")
row1 = int(input("Enter no of rows in first matrix: "))
col1= int(input("Enter no of cols in first matrix: "))
row2= int(input("Enter no of rows in second matrix: "))
col2= int(input("Enter no of cols in second matrix: "))
def main():
    print("1. Accept two matrices from user:")
    print("2. Show the matrices values:")
    print("3. Addition of Two Matrices:")
    print("4. Subtraction of Two Matrices:")
    print("5. Multiplication of Two Matrices:")
    print("6. Transpose of Matrix")
    print("7. Exit")
    ch=int(input("Enter your choice:"))
    if ch == 1:
        print("please enter the values for First Matrix:")
        accept(m1, row1, col1)
        print("please enter the values for Second Matrix:")
        accept(m2, row2, col2)
        main()
    elif ch == 2:
        print("The Value of First matrix is as follows: ")
        show (m1, row1, col1)
        print("The Value of Second matrix is as follows: ")
        show(m2, row2, col2)
        main()
        
    elif ch == 3:
        print("The addition of two matrices are as follows..")
        if ((row1== row2) and (col1 ==col2)):
            add_mat(m1, m2, row1, col1)
            show(res, row1, col1)
        else:
            print("Sorry!!! Addition is not possible...")
        main()
        
    elif ch == 4:
        print("The subtraction of two matrices are as follows..")
        if ((row1 == row2) and (col1 == col2)):
            sub_mat(m1, m2, row1, col1)
            show(res, row1, col1)
        else:
            print("Sorry!!! Subtraction is not possible...")
        main()
    elif ch == 5:
        print("The Multiplication of two matrices are as follows..")
        if (col1== row2):
            mul_mat (m1, m2, row2, col1)
            show(res, row2, col1)
        else:
            print("Sorry!!! Multiplication is not possible...")
        main()
    elif ch == 6:
        show(m1, row1, col1)
        print("Before Transpose of Matrix the elements in matrix are as follows: ")
        print("After applying Transpose on matrix elements are as follows: ")
        trans_mat(m1, row1, col1)
        show(res, row1, col1)
        main()
    elif ch == 7: 
        break  
    else:
        print("Please enter valid choice...")
    

#Function Name: accept

#Use: To accept elements from user for matrices and store it in matrix
def accept(m, row, col):
    for i in range(row):
        c = []
        for j in range(col):
            no=int(input("Enter the value of matrix["+ str(i)+"]["+ str(j) + "]:: "))
            c.append(no)
            print("------------")
            m.append(c)
#Function Name: show

#Use: To display elements from the matrices

def show(m, row, col):
    for i in range(row):
        for j in range(col):
            print(m[i][j], end=" ")
        print()
#Function Name: add_mat

# Use: To perform addition of two matrices
def add_mat(m1, m2, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j] =m1[i][j] + m2[i][j] 

#Function Name: sub_mat

# Use: To perform substraction of two matrices



def sub_mat(m1, m2, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j]=m1[i][j] - m2[i][j]
#Function Name: mul_mat

# Use: To perform multiplication of two matrices

def mul_mat (m1, m2, row, col):
    for i in range(row):
        for j in range(col):
            for k in range(col):
                res[i][j] = res[i][j] + m1[i] [k] * m2[k][j]

#Function Name: trans_mat

# Use: To perform transpose of a matrix

def trans_mat (m, row, col):
    for i in range(row):
        for j in range(col):
            res[i][j] = m[j][i]
main()


