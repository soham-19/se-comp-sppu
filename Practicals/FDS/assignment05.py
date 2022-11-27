
'''Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
Selection Sort
Bubble sort and display top five scores.'''


#Name : Soham Arun Kulkarni
#RollNo.:68
#Div:B

##First year percentage of students
#sorting this data using selection sort.
def SelectionSort(data,n):
    temp=0
    for i in range(n-1):
        for j in range(i+1,n-1):
            if(data[i]<data[j]):
                temp=data[i]
                data[i]=data[j]
                data[j]=temp
            j+=1
        i+=1
    print("***Sorting using Selection sort***")
    print(data)
    print()
    for i in range(0,6):
        print("top five scores are")
        print(data[i])
    print()

#sorting this data using bubble sort.
def bubbleSort(data,n):
    for i in range(n-1):
        for  j in range(n-i-1):
            if(data[j]>data[j+1]):
                temp=data[j]
                data[j]=data[j+1]
                data[j+1]=temp
    print("***Sorting using Bubble sort***")
    print(data)
    print()
  
##__main__
print("Enter percentage for more than 5 students:")
ele=int(input("input no. of students:"))
if(ele>5):
    print("Enter percentage of first year students", end="\n")
    data=[]
    for i in range(ele):
        print("Student",i+1,"=", end='\t')
        stud=float(input())
        data.append(stud)
    n=len(data)
    
    bubbleSort(data,n)
    
    SelectionSort(data,n)