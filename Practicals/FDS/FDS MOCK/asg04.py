'''
Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using binary search (recursive and non- recursive). Insert friend if not present
in phonebook .Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using Fibonacci/Linear search. Insert friend if not present in phonebook.
'''

def sortFriends(List):
    for i in range(len(List)-1):
        minPos = i
        for j in range(i+1,len(List)):
            if(List[j][0] < List[minPos][0]):
                minPos = j

        temp = [List[i][0], List[i][1]]

        List[i][0] = List[minPos][0]
        List[i][1] = List[minPos][1]
        List[minPos][0] = temp[0]
        List[minPos][1] = temp[1]

def makeList(List,n):
    for i in range(n):
        addFriend(List)

def addFriend(List):
    print("Enter name :", end=" ")
    name = input()
    print("Enter phn no. :", end=" ")
    phn = int(input())
    List.append([name,phn])
    sortFriends(List)

def printList(List):
    for i in range(len(List)):
            print("Friend ", i+1, ")", sep="")
            print("\tName :", List[i][0])
            print("\tPhn No. :", List[i][1])

def binSearch(List, key, start, end):
    if start <= end:
        mid = (start+end)//2

        if List[mid][0] == key:
            return mid;
        elif List[mid][0] < key:
            return binSearch(List, key, mid+1, end)
        else:
            return binSearch(List, key, start, mid-1)
        
    return -1;

def linSearch(List, n, key):
    for i in range(n):
        if List[i][0] == key:
            return i
    return -1
    
def fibSearch(List, key):
    offset = -1;
    n = len(List)
    f1 = 0
    f2 = 1
    f3 = f1+f2
    while f3< n:
        f1 = f2
        f2 = f3
        f3 = f1+f2
    while f3 > 1:
        i = min(offset+f1, n-1)
        if List[i][0]==key:
            return i
        else:
            if key < List[i][0]:
                f3 = f1
                f2 = f2-f1
                f1 = f3-f2
            else:
                f3 = f2
                f2 = f1
                f1 = f3-f2
                offset = i
    if f2 and List[offset+1][0] == key:
        return offset+1
    return -1
    


List = []


def loop():
    while(True):
        process()
def process():

    print("\t\t\tMAIN MENU")
    print("\t\t1-Make Record")
    print("\t\t2-Add more friends")
    print("\t\t3-Display Friends")
    print("\t\t4-Search Friend by Binary ")
    print("\t\t5-Search Friend by Fibonacci")
    print("\t\t6-Count Friend")
    print("\t\t0-Exit")
    print("\t\t-> Enter your choice ", end=" ")
    ch = int(input())

    if(ch == 1):
        n = int(input(("How many friends do you want to add ? ")))
        makeList(List, n)
        print(n , " friends added to phone-book !")

    elif ch==2:
        addFriend(List)

    elif ch==3:
        printList(List)

    elif ch==4:
        key = input("Enter friend's name to search :\n->")
        ans = binSearch(List, key, 0, len(List)-1)
        if ans == -1. :
            print("Friend not found !")
        else:
            print("Friend found at index :", ans)

    elif ch==5:
        key = input("Enter friend's name to search :\n->")
        ans = fibSearch(List, key)
        if ans == -1 :
            print("Friend not found !")
        else:
            print("Friend found at index :", ans)

    elif ch==6:
        print("Friends : ", len(List))

    elif ch == 0:
        exit(0)


loop()