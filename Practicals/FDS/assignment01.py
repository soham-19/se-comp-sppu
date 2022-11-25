'''
    ASSIGNMENT 01

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency


'''


def getData(list, max_size):

    print()
    print("Enter FDS marks of %d students." % n)
    print("Kindly enter -1 if student was absent")
    print()

    for i in range(max_size):
        print("Enter score of student ", (i+1))
        marks = int(input())
        if (marks < -1 or marks > 100):
            print("INVALID INPUT")
            break
        list.append(marks)


def printResult(list, max_size):

    print()
    print("RESULT:")
    print()
    print("\tROLL NO. : SCORE")

    for i in range(0, max_size):
        print("\t     ",i+1, " : ", list[i] if list[i] != -1 else "absent")
    print()


def getAverage(list, max_size):

    sum = 0
    for i in list:
        if (i != -1):
            sum += i

    return sum / max_size


def getMaxScore(list):

    maxScore = list[0]

    for i in list:
        if (i > maxScore):
            maxScore = i

    return maxScore


def getMinScore(list):
    minScore = list[0]

    for i in list:
        if (i == -1):
            continue
        if (i < minScore):
            minScore = i

    return minScore


def countAbsentStudents(list):

    absent = 0
    for i in list:
        if (i == -1):
            absent += 1

    return absent


def highestFrequency(list):

    counter = 0
    num = list[0]

    for i in list:
        if (i == -1):
            continue

        currentFreq = list.count(i)

        if (currentFreq > counter):
            counter = currentFreq
            num = i
    return num


#                            main function


FDS_Marks_list = []

n = int(input("Enter the number of students.\t"))

getData(FDS_Marks_list, n)

printResult(FDS_Marks_list, n)

print("Average score of class is ", getAverage(FDS_Marks_list, n), end="\n\n")

print("Highest Score : ", getMaxScore(FDS_Marks_list), end="\n\n")

print("Lowest Score : ", getMinScore(FDS_Marks_list), end="\n\n")

print("No. of Absent Sudents for test :", countAbsentStudents(FDS_Marks_list), end="\n\n")

print("Marks having highest frequency : ", highestFrequency(FDS_Marks_list), end="\n\n")
