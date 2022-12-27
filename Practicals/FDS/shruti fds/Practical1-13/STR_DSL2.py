'''Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string'''

#Name: Shruti Ware
#Class: SE
#Div:B

#input string from user.
str1=input("Enter the string : ")
List=str1.split(" ")
print(List)
#length=len(List)
'''a) To display word with the longest length'''
def long_len():
	lon_len=0
	for word in List:
		if(len(word)>lon_len):
			lon_len=len(word)
			wrd=word
	print("The longest word is : ",wrd)
long_len()
			                                                                                                                                                                     
'''b) To determines the frequency of occurrence of particular character in the string.'''
def freq():
	char=input("Enter character to find its occurence: ")
	count=0
	for j in str1:
		if j==char:
			count+=1
	print("Frequency of ",char,"is :",count)
freq()

'''c) To check whether given string is palindrome or not.'''
def pald():
	if str1[:]==str1[::-1]:
		print("String is palindrome")
	else:
		print("String is not palindrome")
pald()

'''d) To display index of first appearance of the substring.'''
def sub_str():
	sub_str=input("Enter substring:")
	print("If substring is not present return -1\n Else return its index ")
	print(str1.find(sub_str))
sub_str()

'''e) To count the occurrences of each word in a given string.'''
def occur(word):
	count1=0
	for l in range(0,len(List)):
		if (word==List[l]):
			count1+=1
	print("Occurence of",word," is ",count1)
for i in List:
	occur(i)