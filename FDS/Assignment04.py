
'''Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using binary search (recursive and non- recursive). Insert friend if not present
in phonebook .Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using Fibonacci/Linear search. Insert friend if not present in phonebook.'''


def sort_friends(friend_book):
    n = len(friend_book)

    for i in range(n-1):
        minPos = i
        for j in range(i+1, n):
            if friend_book[j][0] < friend_book[minPos][0]:
                minPos = j

        friend_book[minPos][0], friend_book[i][0] = friend_book[i][0], friend_book[minPos][0]


def add_friend(friend_book, name):
    phn = input("Enter the Phn No : ")
    friend_book.append([name, phn])
    sort_friends(friend_book)


def make_list(friend_book):
    n = int(input("Enter how many friends do you want to add "))
    for i in range(n):
        name = input("Enter name : ")
        add_friend(friend_book, name)


def print_friend_list(friend_book):
    for i in friend_book:
        print("\tName :", i[0])
        print("\tPhn :", i[1])


def binSearch(friend_book, key, start, end):

    if start <= end:

        mid = (start+end)//2

        if friend_book[mid][0] == key:
            return mid

        elif friend_book[mid][0] < key:
            return binSearch(friend_book, key, mid+1, end)
        else:
            return binSearch(friend_book, key, start, mid-1)

    return -1


def fibSearch(friend_book, key):
    n = len(friend_book)
    offset = -1
    f1 = 0
    f2 = 1
    f3 = f1 + f2

    while f3 < n:
        f1 = f2
        f2 = f3
        f3 = f1 + f2

    while f3 > 1:
        i = min(offset+f1, n-1)

        if friend_book[i][0] == key:
            return i
        elif key < friend_book[i][0]:
            f3 = f1
            f2 = f2 - f1
            f1 = f3 - f2
        else:
            f3 = f2
            f2 = f1
            f1 = f3 - f2
            offset = i

    if f2 == 1 and offset+1 < n and friend_book[offset+1][0] == key:
        return offset+1
    return -1

def linSearch(friend_book, key):

    for i in range(len(friend_book)):
        if friend_book[i][0] == key:
            return i
    return -1
    

friend_book = []
# make_list(friends)
# print_friend_list(friends)

while (True):
    print("MAIN MENU")
    print("1-Accept and add friends")
    print("2-Display Friends-Book")
    print("3-Binary Search")
    print("4-Fibonacci Search")
    print("0-Exit")
    print()

    ch = int(input("Enter your choice\n-> "))

    if ch == 1:
        make_list(friend_book)
    elif ch == 2:
        print_friend_list(friend_book)
    elif ch == 3:

        key = input("Enter name to search ")
        flag = binSearch(friend_book, key, 0, len(friend_book))

        if flag == -1:
            add_friend(friend_book, key)
        else:
            print("Friend found at index", flag+1)

    elif ch == 4:

        key = input("Enter name to search ")
        flag = fibSearch(friend_book, key)

        if flag == -1:
            print("Friend not found !\nLet's add ",
                  key, "to the friends book!!")
            add_friend(friend_book, key)
        else:
            print("Friend found at index", flag+1)
            
    elif ch ==5:
        key = input("Enter name to search ")
        flag = linSearch(friend_book, key)

        if flag == -1:
            print("Friend not found !\nLet's add ",
                  key, "to the friends book!!")
            add_friend(friend_book, key)
        else:
            print("Friend found at index", flag+1)
    elif ch == 0:
        print("T e r m i n a t i n g . . . . . ")
        exit(0)
    else:
        print("Invalid choice...\nLet's try again!!")

'''
OUTPUT:
How many friends information you want to save:4
Enter friends information
Enter detals of friend:
                NAME: cbgh
        MOBILE NUMBER: 786786
Information accepted and stored succefully
Enter detals of friend:
                NAME: tyh
        MOBILE NUMBER: 6547657
Information accepted and stored succefully
Enter detals of friend:
                NAME: uiop
        MOBILE NUMBER: 657687
Information accepted and stored succefully
Enter detals of friend:
                NAME: tre
        MOBILE NUMBER: 6868768
Information accepted and stored succefully
Friends Information
           NAME:  cbgh
        Mobile Number: 786786


           NAME:  tyh
        Mobile Number: 6547657


           NAME:  uiop 
        Mobile Number: 657687


           NAME:  tre
        Mobile Number: 6868768


[['cbgh', '786786'], ['tyh', '6547657'], ['uiop', '657687'], ['tre', '6868768']]
--------------------------------------------------------------------------------

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.1
enter name of friend that you want to insert:thyu
enter mob_no:786878
[['cbgh', '786786'], ['tyh', '6547657'], ['uiop', '657687'], ['tre', '6868768'], ['thyu', '786878']]

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.2

Enter element to be searched tre
Element found at index: -1

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.2

Enter element to be searched uiop
Element found at index: 2

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.4
PS D:\Ashiya\DSL> python -u "d:\Ashiya\DSL\assign4.py"
How many friends information you want to save:3
Enter friends information
Enter detals of friend:
                NAME: abc
        MOBILE NUMBER: 87687
Information accepted and stored succefully
Enter detals of friend:
                NAME: bhi
        MOBILE NUMBER: 878797
Information accepted and stored succefully
Enter detals of friend:
                NAME: uio
        MOBILE NUMBER: 78897
Information accepted and stored succefully
Friends Information
           NAME:  abc
        Mobile Number: 87687


           NAME:  bhi
        Mobile Number: 878797


           NAME:  uio
        Mobile Number: 78897


[['abc', '87687'], ['bhi', '878797'], ['uio', '78897']]
--------------------------------------------------------------------------------

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.1
enter name of friend that you want to insert:thy
enter mob_no:8789797
[['abc', '87687'], ['bhi', '878797'], ['uio', '78897'], ['thy', '8789797']]

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.2

Enter element to be searched uio
Element found at index: 2

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.3

Enter element to be searched bhi
Found at index : 1

 Enter your choice
1.Insert a friend
 2.Binary search .
3.Fibo search.4
'''