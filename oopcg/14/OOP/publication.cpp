#include <iostream>
#include <string.h>
using namespace std;
class Publication
{
protected:
	string title;
	float price;

public:
	virtual void getdetails() = 0;
	virtual void display() = 0;
};
class book : public virtual Publication
{
	int pagecount;

public:
	void getdetails()
	{

		cout << "enter the title of book" << endl;
		cin >> title;
		cout << "enter the price of  book" << endl;
		cin >> price;
		try
		{
			if (price > 1000)
			{

				throw(price);
			}
		}
		catch (float)
		{
			cout << "enter the affordable price" << endl;
			cin >> price;
		}
		cout << "enter the pagecount of  book" << endl;
		cin >> pagecount;
	};

	void display()
	{
		cout << "title of boook is:" << title << endl;
		cout << "price of book is:" << price << endl;
		cout << "pagecount of book is:" << pagecount << endl;
	}
};

class audiobook : public virtual Publication
{
	int playtime;

public:
	void getdetails()
	{

		cout << "enter the title of audiobook" << endl;
		cin >> title;
		cout << "enter the price of audiobook" << endl;
		cin >> price;
		try
		{
			if (price > 1000)
			{
				cout << "price is high " << endl;
				throw(price);
			}
		}
		catch (float)
		{
			cout << "enter the affordable price" << endl;
			cin >> price;
		}
		cout << "enter the playtime of audiobook" << endl;
		cin >> playtime;
	};
	void display()
	{
		cout << "title of boook is:" << title << endl;
		cout << "price of book is:" << price << endl;
		cout << "playtime of book is:" << playtime << endl;
	}
};

int main()
{
	int choice, n;
	Publication *p[50];
	int i = 0;
	
	do
	{
	          cout << "enter the choice:" << endl << "1.book" << endl<< "2.audiobook" << endl<< "3.display" << endl;
	          cout<<"enter the choice"<<endl;
	          cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "book" << endl;
			p[i] = new book(); 
			p[i]->getdetails();
			i++;
			break;

		case 2:
			cout << "audiobook" << endl;
			p[i] = new audiobook;
			p[i]->getdetails();
			i++;
			break;
		case 3:
			cout << "details" << endl;
			n = i;
			for (int j = 0; j<n; j++)
			{
				
				p[j]->display();
				
			
			}
				break;
			case 4:
				cout << "End of the program!!!";
				
				break;
			default:
				break;
			
		}

	} while (choice < 3);

	return 0;
}
