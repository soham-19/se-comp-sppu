def display(matrix):
    for row in matrix:
        for element in row:
            print(element,end=" ")
        print()
    
def convert(matrix):
    sp = []

    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] != 0:
                temp = []
                temp.append(i)
                temp.append(j)
                temp.append(matrix[i][j])

                sp.append(temp)

    # displaying sparse matrix 

    print("\nSparse Matrix :")
    print("R C V")
    display(sp)


a = [
        [1,0,0],
        [0,0,5],
        [0,0,3]
    ]

display(a)

convert(a)