
'''
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
'''


##Name : Soham Arun Kulkarni
##RollNo.:68
##Div:B

#                                           functions

def getStr():
    str = input("Enter the main string\t")
    return str

def getSub():
    sub = input("Enter the sub-string\t")
    return sub

def maxLen(str):
    list = str.split(" ")
    max = list[0]
    for i in list:
        if len(i) > len(max):
            max = i
    return max

def printOcc(str):
    list = str.split(" ")
    checked = []
    for i in list:
        if (i in checked):
            continue
        print (i ," : ", list.count(i))
        checked.append(i)
      
def findOccOf(str,item):
    count = int(0)
    list = str.split(" ")
    for i in list:
        if i == item :
            count +=1
    return count
    
def isPal(str):

    start = 0
    end = len(str)-1

    while(start<=end):
        if(str[start] == str[end]):
            start +=1
            end -=1
        else:
            print(str+" is not palindrome")
            return
        
    print (str+" is palindrome")

def firstOccIndex(str,sub):
    return str.find(sub)


#                                       main program
while True:

    print("1.To display word with maximum length")
    print("2.To print occurances of each word in the string")
    print("3.To print occurance of exact word in the string")
    print("4.To check if the string is palindrome or not")
    print("5.To print the index of first occurance of the substring")
    print("0.To exit")
    print()

    ch = int(input("Enter your choice\t"))
    
    if (ch == 0):
        print("Exiting the program.....")
        print("Exited the program successfully.....")
        exit()

    elif ch == 1:
        print(maxLen(getStr()))

    elif ch == 2:
        printOcc(getStr())   

    elif ch == 3:
        print(findOccOf(getStr(),getSub()))

    elif ch == 4:

        isPal(getStr())      
    elif ch == 5:

        print(firstOccIndex(getStr(),getSub()))
        
    print()