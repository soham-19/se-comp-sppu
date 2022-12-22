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
    str = input("==>")
    return str


def get_sub_string():
    print("Enter sub string.")
    str = input("==>")
    return str


def word_with_longest_length(str):
    list = str.split(" ")
    ans = list[0]

    for i in list:
        if len(i) > len(ans):
            ans = i
    return ans


def freqency_of_character(str, ch):
    ans = 0
    for i in str:
        if i == ch:
            ans += 1
    return ans


def check_palindrome(str):
    low = 0
    high = len(str)-1

    while (low <= high):
        if str[low] != str[high]:
            print(str, " is not palindrome.")
            return
        else:
            low += 1
            high -= 1

    print(str, " is palindrome.")


def first_occurrence_of_substring(str, substr):
    return str.find(substr)


def occurances_of_each_word(str):

    list = str.split(" ")
    checked = []
    occ = []

    for i in list:
        if i not in checked:
            count = 0
            for j in list:
                if j == i:
                    count += 1

            checked.append(i)
            occ.append(count)

    for i in range(len(occ)):
        print(checked[i], " : ", occ[i])


"""                                                              main                                                         """

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
