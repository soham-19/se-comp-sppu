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

class Publication
{
    public:
        string title;
        float price;

        virtual void set_data() = 0;
        virtual void print_data() = 0;

};

class Book : public virtual Publication
{
    public:
        int pg_count;

        Book();

        void set_data();
        void print_data();
};

class Tape : public virtual Publication
{
    public:
        float playing_time;

        Tape();

        void set_data();
        void print_data();
};

Book::Book(){
    set_data();
}

void Book::set_data(){

    cout << "Enter book Title : ";
    fflush(stdin);
    getline(cin, title);

    try
    {
        cout << "Enter price : ";
        cin >> price;
        
        if(price > 1000)
            throw(price);
    }
    catch(float)
    {
        do{
            cout << "Huge amount !!\nEnter affordable price : ";
            cin >> price;
        }
        while(price > 1000);
    }

    cout << "Enter page count : ";
    cin >> pg_count;

}

void Book::print_data() {

    cout << "\t\tBook : \n";
    cout << "\t\t\tTitle : " << title <<endl;
    cout << "\t\t\tPrice : Rs. " << price <<endl;
    cout << "\t\t\tPage Count : " << pg_count <<endl << endl;
}

Tape::Tape(){
    set_data();
}

void Tape::set_data() {

    cout << "Enter cassette title : ";
    fflush(stdin);
    getline(cin,title);

    try{
        cout << "Enter price : ";
        cin >> price;

        if(price > 1000)
            throw(price);
    }
    catch(float){

        do{
            cout << "Very Costly!!\nPlease enter affordable price!!  ";
            cin >> price;
        }
        while(price > 1000);
    }

    cout << "Enter running time in minutes : ";
    cin >> playing_time;

}

void Tape::print_data() {

    cout << "\t\tTape : \n";
    cout << "\t\t\tTitle : " << title <<  endl;
    cout << "\t\t\tPrice : Rs. " << price << endl;
    cout << "\t\t\tPlaying Time : " << playing_time << " (mins)"<< endl <<  endl;

}

int main() {

    Publication * p[50];
    int i = 0;

    while(true) {

        cout << "   M   E   N   U" << endl <<endl;
        cout << "1-Add Book\n"
             << "2-Add Cassette\n"
             << "3-Display\n"
             << "0-Exit\n";
        
        int ch;

        cout << "Enter your choice\n==> ";
        cin >> ch;

        switch(ch) {

            case 0:
                cout << "TERMINATING\n\n";
                exit(0);
            case 1:
                p[i++] = new Book;
                cout << "Book added !\n";
                break;
            case 2:
                p[i++] = new Tape;
                cout << "Tape added !\n";
                break;
            case 3:
                if(i==0){
                    cout << "Nothing to display!\n";
                    break;
                }
                cout << "Displaying Records\n";

                for(int j=0; j<i; j++)

                    p[j]->print_data();
                
                break;

            default:
                cout << "Invalid Choice!!\nLet's Try Again!\n";

        }
    }
}