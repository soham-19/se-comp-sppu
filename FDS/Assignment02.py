'''
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
'''

def getStr():
    print("Enter main string\n->",end=" ")
    return input()

def get_substring():
    print("Enter sub-string\n->",end=" ")
    return input()

def word_with_maxLength(str):

    List = str.split(" ")
    # print(List)

    maxLenWord = List[0]
    for i in List:

        if len(i) > len(maxLenWord):
            maxLenWord = i

    return maxLenWord

def freqOfChar(ch,str):
    count = 0

    for i in str:
        if ch == i:
            count += 1

    return count

def palindrome(str):

    start = 0
    end = len(str)-1

    while(start <= end):
        if str[start] != str[end]:
            return False
        start += 1
        end -= 1

    return True

def firstOccIndex(str, sub):
    n = len(str)
    m = len(sub)
    for i in range(n):

        if str[i] == sub[0]:
            
            for j in range(1,m):

                if str[i+j] != sub[j]:
                    break
            else:
                return i
    else:
        return -1

def occurances_of_each_word(str):
    checked = []

    List = str.split(" ")

    for i in List:
        if i not in checked:
            checked.append(i)
            print(i, ":",List.count(i))

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
        print(word_with_maxLength(getStr()))

    elif ch == 2:
        occurances_of_each_word(getStr())   

    elif ch == 3:
        print(freqOfChar('c',getStr()))

    elif ch == 4:

        print(palindrome(getStr()) )     
    elif ch == 5:

        print(firstOccIndex(getStr(), get_substring()))
        
    print()



'''OUTPUT:
Enter a string: have a good day
Enter your choice:
1.longest word 
2.frquency of character.
3.pallindrome
4.Finding substring
5.ocrance of word.
6.exit
1
The longest word is :  have a good day
Enter your choice:
1.longest word
2.frquency of character.
3.pallindrome
4.Finding substring
5.ocrance of word.
6.exit
2
Enter the character to find its occurance:have
Frequency of  have is : 0
Enter your choice:
1.longest word
2.frquency of character.
3.pallindrome
4.Finding substring
5.ocrance of word.
6.exit
3
Enter string to check input: nayan
String is palindrome.
Enter your choice:
1.longest word
2.frquency of character.
3.pallindrome
4.Finding substring
5.ocrance of word.
6.exit
4
Enter substring:go
8
Enter your choice:
1.longest word
2.frquency of character.
3.pallindrome
4.Finding substring
5.ocrance of word.
6.exit
5
Enter word to search: good
1
Enter your choice:
1.longest word
2.frquency of character.
3.pallindrome
4.Finding substring
5.ocrance of word.
6.exit
6
'''
