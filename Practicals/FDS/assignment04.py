
'''Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using binary search (recursive and non- recursive). Insert friend if not present
in phonebook .Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using Fibonacci/Linear search. Insert friend if not present in phonebook.'''

#Name : Soham Arun Kulkarni
#RollNo.:31
#Div:B
def accept_array(A):
	n=int(input("How many  friends information you want to save : "))
	print("Enter friend's information")
	for i in range(n):
		print("\tEnter details of friend %d : "%(i+1))
		name=input("\t\tNAME : ")
		mob=input("\t\tMOBILE NUMBER : ")
		X=[name,mob]
		A.append(X)
	print("INFORMATION STORED SUCCESSFULLY!!")
	return n
def display_array(A,n):
	if n==0:
		print("\nNo records found")
	else:
		print("Friend's information : ")
		for i in range(n):
			print("\tFriend %d : %10s %s "%((i+1),A[i][0],A[i][1]))
		print("\n")

def BIN(A,s,l,X):
	if s<=l:
		m=int((s+l)/2)
		if(A[m][0]==X):
			return m
		else:
			if(X < A[m][0]):
				return BIN(A,s,m-1,X)
			else:
				return BIN(A,m+1,l,X)
	return -1 #not found

def fibonacci_search(A,n,X):
	f1=0
	f2=1
	f3=f1+f2
	offset = -1
	while f3<n:
		f1=f2
		f2=f3
		f3=f1+f2
	while f3>1:
		i=min(offset+f1,n-1)
		if(A[i][0]==X):
			return i
		else:
			if X<A[i][0]:
				f3=f1
				f2=f2-f1
				f1=f3-f2
			else:
				f3=f2
				f2=f1
				f1=f3-f2
				offset = i
	if(f2==1 and (offset+1)<n and A[offset + 1][0]==X):
		return offset +1
	return -1
def insert_the_friend(A,n,name):
	mob=input("Enter mobile number : ")
	X=[name,mob]
	A.append(X)
	j=n-1
	while(j>=0):
		if (A[j][0]<=name):
			break
		else:
			A[j+1]=A[j]
		j=j-1
	A[j+1]=X
	print("\nINFO STORED SUCCESSFULLY!!")
	display_array(A,n+1)
def choice():
	A=[]
	while True:
		print("\n")
		print("\t1 :Accept & display friend's info")
		print("\t2 :Binary Search")
		print("\t3 :Fibonacci Search")
		print("\t4 :EXIT!!")
		ch=int(input("Enter your choice : "))
		if ch==4:
			print("\n\t\tEXIT!!")
			break
		elif ch==1:
			A=[]
			n=accept_array(A)
			display_array(A,n)
		elif ch==2:
			X=input("Enter name(search) : ")
			flag = BIN(A,0,n-1,X)
			if flag==-1:
				print("\n\tFriend not found :(")
				insert_the_friend(A,n,X)
				n=n+1
			else:
				print("\n\t:) Friend found at location %d"%(flag+1))
		
		elif ch==3:
			X=input("Enter name(search) : ")
			flag=fibonacci_search(A,n,X)
			if flag==-1:
				print("\n\tFriend not found :(")
				insert_the_friend(A,n,X)
				n=n+1
			else:
				print("\n\t:) Friend found at %d"%(flag+1))
choice()