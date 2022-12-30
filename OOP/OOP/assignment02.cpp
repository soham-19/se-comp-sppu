/*
    Develop a program in C++ to create a database of
    student’s information system containing the following
    information: Name, Roll number, Class, Division,
    Date of Birth, Blood group, Contact address,
    Telephone number, Driving license no. and other.
    Construct the database with suitable member
    functions. Make use of constructor, default
    constructor, copy constructor, destructor, static
    member functions, friend class, this pointer, inline
    code and dynamic memory allocation operators-new
    and delete as well as exception handling.
*/

#include<iostream>
using namespace std;

class Student{
        int roll_no;
        string name;
        string std;
        char div;
        string dob;
        string blood_grp;
        string phn_no;
        string addr;
        static int count;
    public:

        void getData();
        static void getCount();
        friend inline void printData(Student&);

        Student(){
            cout << "object created!\n";
            count++;
            name = "n/a";
            roll_no = count;
            std = "se";
            div = '-';
            dob = "01/01/2003";
            blood_grp = "A+";
            phn_no = "0000000000";
            addr = "KKWIEER";
        }
        //copy const
        Student(Student & obj){
            cout << "object created using copy constructor!\n";
            name = obj.name;
            roll_no = obj.roll_no;
            std = obj.std;
            div = obj.div;
            dob = obj.dob;
            blood_grp = obj.blood_grp;
            phn_no = obj.phn_no;
            addr = obj.addr;
            count++;
        }

        ~Student(){
            cout << "Destroying the object having roll number " << roll_no << "\n";
            count--;
        }
};

int Student::count = 0;

void Student::getData(){

    cout << "Enter name : ";
    fflush(stdin);
    getline(cin,name);

    cout << "Enter roll number : ";
    cin >> roll_no;

    cout << "Enter standard : ";
    fflush(stdin);
    getline(cin,std);

    cout << "Enter div : ";
    fflush(stdin);
    div = getchar();

    cout << "Enter DOB : ";
    fflush(stdin);
    getline(cin,dob);

    cout << "Enter blood group : ";
    fflush(stdin);
    getline(cin,blood_grp);

    cout << "Enter Phone Number : ";
    fflush(stdin);
    getline(cin,phn_no);

    cout << "Enter Address : ";
    fflush(stdin);
    getline(cin,addr);
}

inline void printData(Student& obj){
    cout << "\n\t"
         << obj.roll_no << "\t"
         << obj.name << "\t"
         << obj.std << "\t" 
         << obj.div << "\t"
         << obj.dob << "\t"
         << obj.phn_no << "\t"
         << obj.blood_grp << "\n";
}

void Student::getCount(){
    cout << "Count : " << count << endl;
}

int main(){

    Student stud1;              // normal creation of object;
    Student stud2(stud1);       // object creation using copy constructor
    int i, n;

    cout << "Enter number of students you want to add : ";
    cin >> n;
    Student *s_arr[n];

    for( i=0; i<n+2; i++)
        s_arr[i] = new Student;     // new operator

    for( int i=0; i<n; i++)
    {
        cout << "* Student " << i+1 << " : " << endl;
        s_arr[i]->getData();
    }
    s_arr[i++] = &stud1;
    s_arr[i] = &stud2;
    Student::getCount();
    cout << "\n"
         << "ROLL NO." << "\t"
         << "NAME" << "\t"
         << "STD" << "\t" 
         << "DIV" << "\t"
         << "DOB" << "\t"
         << "PHN" << "\t"
         << "BLOOD GRP" << "\n";
    cout << "--------------------------------------------------------------" << endl;
    
    for( int i=0; i<n+2; i++)
    {
        cout << "* Student " << i+1 << " : " << endl;
        printData(*s_arr[i]);
        cout << "--------------------------------------------------------------" << endl;
    }
    Student::getCount();

    for(i=0; i<n;i++)
        delete s_arr[i];        // delete operator
    
    Student::getCount();
    return 0;
}