'''
    ASSIGNMENT 01

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency

'''

def getMarks(marks, n):

    print("Enter marks of ", n, " students :")

    for i in range(n):
        print("-> Student ", i+1,end=" : ")
        x = int(input())
        
        if x<-1 or x>100:
            print("Invalid marks!!")
            print("Try again !")
            exit(0)
        else:
            marks.append(x)

    print("Record saved successfully.")

def printResult(list):

    print("* RESULT *")
    print()
    print("NO.: SCORE")

    for i in range(len(list)):
        
        print(i+1, " : ", "absent" if list[i]==-1 else list[i])

def avgeScore(list):
    sum = int(0)

    for i in list:
        if i > -1 :
            sum += i
    
    print(" Average score of class : ", sum/len(list))

def maxMinScore(list):
    largest = int(0)
    smallest = int(101)

    for i in list:
        if i == -1:
            continue

        if i > largest:
            largest = i
        if i < smallest:
            smallest = i
    
    print("Maximum score is : ", largest)
    print("Minimum score is : ", smallest)

def countAbsentStudents(list):
    count = int(0)

    for i in list:
        if i == -1:
            count += 1

    print("Count of absent students : ", count)

def maxMinFreq(list):

    high = list[0]
    low = list[0]

    for i in list:

        if(i==-1):
            continue

        if list.count(i) > list.count(high):
            high = i

        if list.count(i) < list.count(low):
            low = i

    print("Marks with highest frequency : ", high)
    print("Marks with highest frequency : ", low)




#                                                        main

marksList = []

n = int(input("Enter the number of students.\t"))
getMarks(marksList, n)
printResult(marksList)
avgeScore(marksList)
countAbsentStudents(marksList)
maxMinScore(marksList)
maxMinFreq(marksList)