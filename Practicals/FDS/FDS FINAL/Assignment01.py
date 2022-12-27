'''
    ASSIGNMENT 01

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency

'''

def getMarks():

    print("Enter total number of students : ", end="")
    n = int(input())

    List = []
    print("Enter -1 if student was absent.")
    print("Enter marks of ", n, "students :")

    for i in range(n):
        print("\t-> Student",i+1, end=" : ")
        List.append(int(input()))

    # updating wrong input value
    for i in range(n):
        if List[i] < -1:
            List[i] = 0
        if List[i] > 100:
            List[i] = 100

    return List

def printResult(marks):
    print()
    print("*****RESULT*****")
    print("\tNo : Score")
    for i in range(len(marks)):
        print("\t",i+1,":","absent" if marks[i]==-1 else marks[i])
    print()

def getAverage(marks):

    sum = 0
    for i in marks:
        if i != -1:
            sum += i
    
    return sum/len(marks)

def getMinMax(marks):
    max = -100
    min = 100

    for i in marks:
        if i == -1:
            continue
        if i < min:
            min = i
        if i > max:
            max = i

    return [min,max]

def countAbsent(marks):
    count = 0
    for i in marks:
        if i == -1:
            count += 1
    return count

def maxFreq(marks):
    checked = []
    maxFreq = 0
    result = 0
    for i in marks:
        if i not in checked:
            checked.append(marks.count(i), maxFreq)
            if marks.count(i) == maxFreq:
                result = i

    return [result,maxFreq]
marks = getMarks()
# printResult(marks)
avg = getAverage(marks)
minMax = getMinMax(marks)
absent = countAbsent(marks)
maxFrequency = maxFreq(marks)

printResult(marks)
print("Average score of class is :", avg)
print("Minimum Score :", minMax[0])
print("Maximum Score :", minMax[1])
print("Count of Absent Students :", absent)
print("Marks with maximum frequency :", maxFrequency[0], "frequency =",maxFrequency[1])