    /*
    Imagine a publishing company which does marketing
    for book and audio cassette versions. Create a class
    publication that stores the title (a string) and price
    (type float) of publications. From this class derive two
    classes: book which adds a page count (type int) and
    tape which adds a playing time in minutes (type float).
    Write a program that instantiates the book and tape
    class, allows user to enter data and displays the data
    members. If an exception is caught, replace all the
    data member values with
    zero values.
    */

#include<iostream>
using namespace std;

class Publication{

    public:
        string title;
        float price;

        virtual void getData() = 0;
        virtual void printData() = 0;

};

class Book : public Publication {

    public:
        int page_count;

        Book(){
            getData();
        }

        void getData();
        void printData();
};

class Tape : public Publication {

    public:
        float time;

        Tape(){
            getData();
        }

        void getData();
        void printData();

};

void Book::getData(){

    cout << "Enter book title : ";
    fflush(stdin);
    getline(cin, title);

    try{
        cout << "Enter price of " << title << " book : ";
        cin >> price;

        if(price > 1000)
            throw(price);
    }
    catch(float){

        cout << "Price is very high !!\nEnter affordable price : ";
        cin >> price;
    }

    cout << "Enter page count : ";
    cin >> page_count;

    cout << "Book Added !\n\n";
}

void Tape::getData(){

    cout << "Enter Audio Tape title : ";
    fflush(stdin);
    getline(cin, title);

    try{
        cout << "Enter price of " << title << " Cassette : ";
        cin >> price;

        if(price > 1000)
            throw(price);
    }
    catch(float){

        cout << "Price is very high !!\nEnter affordable price : ";
        cin >> price;
    }

    cout << "Enter time length of the cassette : ";
    cin >> time;

    cout << "Tape Added !\n\n";
}

void Book::printData()
{
	cout<<"\t\tTITLE OF BOOK: "<<title<<endl;
	cout<<"\t\tPRICE OF BOOK: "<<price<<endl;
	cout<<"\t\tPAGE COUNT: "<<page_count<<endl;
}

void Tape::printData()
{
	cout<<"\t\tTITLE OF AUDIO CASSETTE : "<<title<<endl;
	cout<<"\t\tPRICE OF AUDIO CASSETTE : "<<price<<endl;
	cout<<"\t\tTIME OF AUDIO CASSETTE : "<<time<<endl;
}
int main() {

    Publication *p[50];
    int i = 0;

    while(true) {

        cout << "_____MENU_____" << endl
             << "1-Add Book" << endl
             << "2-Add Cassette" << endl
             << "3-Display" << endl
             << "0-Exit" << endl
             << endl;

        int ch;
        cout << "Enter your choice :\n==> ";
        cin >> ch;

        switch(ch){

            case 1:
                p[i++] = new Book;
                break;

            case 2:
                p[i++] = new Tape;
                break;

            case 3:
                if( i == 0){
                    cout << "Nothing is added yet..\n";
                }
                else{
                    for(int j=0; j<i; j++){
                        p[j]->printData();
                        cout << endl;
                    }
                }
                break;

            case 0:
                cout << ".........TERMINATING........." << endl;
                exit(0);
            default:
                cout << "In-valid choice !!\nLet's try again!!\n\n";

        }
    }



    return 0;
}