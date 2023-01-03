#include <iostream>
using namespace std;

class Student{
    private:

    string name;
    string std;
    string dob;
    string blood_grp;
    string addr;
    string phn;
    char div;
    int rollNo;
    static int count;

    public:
    Student(){
        cout << "\tObject created with default constructor!\n";
        rollNo = ++count;
        name = "n/a";
        std = "SE";
        dob = "dd/mm/yyyy";
        blood_grp = "O+";
        addr = "KKWIEER";
        div = 'B';
        phn = "0000000000";

    }

    Student(Student &obj){
        cout << "\tObject created with copy constructor!\n";
        name = obj.name;
        std = obj.std;
        dob = obj.dob;
        blood_grp = obj.blood_grp;
        addr = obj.addr;
        div = obj.div;
        phn = obj.phn;
        rollNo = obj.rollNo ;
        count++;
    }

    ~Student (){
        cout << "Destroying object with roll no. " << rollNo <<"...\n";
        count--;
    }
    
    friend void getData(Student&);
    inline void prinData();
    static void getCount();
};

int Student::count = 0;

void getData(Student & obj){
    
    cout << "Enter roll no. : ";
    cin >> obj.rollNo;
    fflush(stdin);

    cout << "Enter name : ";
    getline(cin,obj.name);
    fflush(stdin);

    cout << "Enter DOB : ";
    getline(cin,obj.dob);
    fflush(stdin);

    cout << "Enter phone no. : ";
    getline(cin,obj.phn);
    fflush(stdin);

    cout << "Enter std : ";
    getline(cin,obj.std);
    fflush(stdin);

    cout << "Enter div : ";
    cin >> obj.div;
    fflush(stdin);

    cout << "Enter blood grp : ";
    getline(cin,obj.blood_grp);
    fflush(stdin);

    cout << "Enter address : ";
    getline(cin,obj.addr);
    fflush(stdin);
}

inline void Student::prinData(){
    cout << rollNo << "\t" << name << "\t" << std << "\t" << div << "\t" << dob << "\t" << phn << "\t" << addr << "\n";
    cout << "---------------------------------------------------------------------------------\n";
}

void Student::getCount(){
            cout << "\t* Objects existing at this moment : " << count << endl;
}

int main(int argc, char const *argv[])
{
    Student s1;
    Student s2(s1);

    cout << ">?";
    int n;
    cin>>n;
    Student * s = new Student[n];

    for(int i=0; i<n; i++){
        getData(s[i]);
    }

    for(int i=0; i<n; i++){
        s[i].prinData();
    }

    s1.prinData();
    s2.prinData();

    for(int i=0; i<n; i++){
        delete &s[i];
    }
    return 0;
}

/*
        Object created with default constructor!
        Object created with copy constructor!
Enter number of objects : 3
        Object created with default constructor!
        Object created with default constructor!
        Object created with default constructor!
Enter roll no. : 12
Enter name : SOHAMM
Enter DOB : 11/11/1111
Enter phone no. : 11111111
Enter std : 12
Enter div : A
Enter blood grp : Q+
Enter address : NASHIK
Enter roll no. : 6
Enter name : KOMALL
Enter DOB : 33/33/3333
Enter phone no. : 3948293829
Enter std : FE
Enter div : T
Enter blood grp : I+
Enter address : PUNE
Enter roll no. : 9
Enter name : XYZ
Enter DOB : 45/45/4545
Enter phone no. : 45676543456
Enter std : BE
Enter div : P
Enter blood grp : Y+o
Enter address : KKW

NO      NAME    STD     DIV     DOB     PHN     ADDRESS
---------------------------------------------------------------------------------
12      SOHAM     12      A       11/11/1111      11111111        NASHIK
---------------------------------------------------------------------------------
6       KOMAL     FE      T       33/33/3333      3948293829      PUNE
---------------------------------------------------------------------------------
9       XYZ     BE      P       45/45/4545      45676543456     KKW
---------------------------------------------------------------------------------
1       n/a     SE      B       dd/mm/yyyy      0000000000      KKWIEER
---------------------------------------------------------------------------------
1       n/a     SE      B       dd/mm/yyyy      0000000000      KKWIEER
---------------------------------------------------------------------------------
Destroying object with roll no. 12...
Destroying object with roll no. 4...
Destroying object with roll no. 9...
Destroying object with roll no. 1...
Destroying object with roll no. 1...
*/
