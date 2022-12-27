'''
    ASSIGNMENT 01

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency

'''

def getMarks(List):
    n = int(input("Enter the number of total students"))
    print("Enter marks. Enter -1 if student was absent")
    for i in range(n):
        print("-> Student ", i+1)
        x = int(input())
        if x <=100 and x>= -1:
            List.append(x)
        else:
            print("Invalid marks!")
            exit(0)
    print("Records saved successfully!")

def printResult(List):
    print("No : Result")
    for i in range(len(List)):
        print(i, " : ", List[i])

def printAvg(List):
    sum = 0
    for i in List:
        if i != -1:
            sum +=i
    print("average score of class : ", sum/len(List))

def getMinMax(List):
    max = 0
    min = 101

    for i in List:
        if i == -1:
            continue
        if i > max:
            max = i
        if i < min:
            min = i
    
    print("Minimum score : ", min)
    print("Maximum score : ", max)

def countAbsent(List):
    count = 0
    for i in List:
        if i == -1:
            count += 1

    print("Absent Students : ", count)

def maxMinFreq(List):
    min = List[0]
    max = List[0]

    for i in List:
        if i != -1:
            if List.count(i) > List.count(max):
                max = i

            if List.count(i) < List.count(min):
                min = i

    print("Max freq : ", max)
    print("Min freq : ", min)

marks = []

getMarks(marks)
printResult(marks)
printAvg(marks)
getMinMax(marks)
countAbsent(marks)
maxMinFreq(marks)