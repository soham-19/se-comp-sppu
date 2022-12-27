'''
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
'''
def get_string():
    print("Enter main string.")
    print("->", end="")
    str = input()
    return str

def get_sub_string():
    print("Enter sub string.")
    print("->", end="")
    str = input()
    return str

def word_with_longest_length(str):
    list = str.split(" ")
    max = list[0]
    for i in list:
        if len(i) > len(max):
            max = i
    
    return max

def freqency_of_character(str, ch):
    count = 0
    for i in str:
        if i==ch:
            count +=1
    return count

def check_palindrome(str):
    if str == str[::-1]:
        print(str, " is palindrome!")
    else:
        print(str, " is not palindrome!")

def first_occurrence_of_substring(str, sub):
    return str.find(sub)

def occurances_of_each_word(str):

    list = str.split(" ")
    checked = []

    for i in list:
        if i not in checked:
            print(i, " : ", list.count(i))
            checked.append(i)
while (True):

    print("    M E N U")
    print("==> 1-To display word with the longest length")
    print("==> 2-To determines the frequency of occurrence of particular character in the string")
    print("==> 3-To check whether given string is palindrome or not")
    print("==> 4-To display index of first appearance of the substring")
    print("==> 5-To count the occurrences of each word in a given string")
    print("\bEnter your choice")

    ch = int(input("==>"))

    if (ch == 1):
        str = get_string()
        print("Word with max length is : ", word_with_longest_length(str))

    elif (ch == 2):
        str = get_string()
        print("Enter the character.")
        c = (input("==>"))

        print("Frequency of ", c, " is : ", freqency_of_character(str, c))

    elif (ch == 3):
        str = get_string()
        check_palindrome(str)

    elif (ch == 4):
        str = get_string()
        sub = get_sub_string()
        if first_occurrence_of_substring(str, sub) == -1:
            print("Not a substring of main string !!")
        else:
            print("First occurance of ", sub, " is at index : ",
                first_occurrence_of_substring(str, sub))

    elif (ch == 5):
        str = get_string()
        occurances_of_each_word(str)

    elif (ch == 0):
        print("T  E  R  M  I  N  A  T  I  N  G  ")
        exit(0)
    else:
        print("Invalid selectin!!\nLet's try again !")
