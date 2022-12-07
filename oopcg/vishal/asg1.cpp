#include <iostream>
#include <string.h>
using namespace std;
class student
{

public:
int rollno;
unsigned long int contact_no;
char name[30];
char blood_grp[5];
char clas[4];
char d[3];
char DOB[10] ;
unsigned long int tele;
static int count;
void getdata();
friend void display(student &obj);

student() //constructor
{
rollno=0;
cout<<"\tConstructor\n";
count = rollno;
count++;
}

static void getcount()
{
cout<<"Count"<<count;
}

student(int rollno)
{
this->rollno=rollno;
}
student(student &obj)
{
   rollno = obj.rollno;
   strcpy(DOB,obj.DOB);
   contact_no = obj.contact_no;
   tele = obj.tele;
   strcpy(name, obj.name);
   strcpy(clas,obj.clas);
   strcpy(d,obj.d);
   
}


~student()
{
cout<<"\n Destructor";
count++;
}
};

int student::count=0;
void student::getdata()
{

    cout<<"Name:";
    cin.getline(name,30);

    cout<<"Roll number:";
    cin>>rollno;

    cout<<"Contact number:";
    cin>>contact_no;

    cout<<"Telephone number:";
    cin>>tele;

    cout<<"Blood group:";
    cin>>blood_grp;

    cout<<"Date of birth:";
    cin>>DOB;

    cout<<"Class :";
    cin>>clas;

    cout<<"Division:";
    cin>>d;
   
    cout<<"***************************************************************************************************************************"<<endl;
}

void display(student &obj)
{
cout<<obj.name;
cout<<"\t"<<obj.rollno;
cout<<"\t"<<obj.clas;
cout<<"\t"<<obj.d;
cout<<"\t\t"<<obj.DOB;
cout<<"\t\t"<<obj.contact_no;
cout<<"\t\t"<<obj.tele;
cout<<"\t\t"<<obj.blood_grp;

}


int main()
{
student s1;
student s2(s1);

s1.getdata();
cout<<"\nName\tRoll No\tClass\tDivision\tDOB\t\tContact No,\t\tTel Ph.No\tBlood group\n";
display(s1);
student*s[10];
int i ,n;
cout<<"\n****************************************************************************************************************************";
cout<<"\nHow many student objects?\n";
cin>>n;
for(i=0;i<n;i++)
s[i]=new student();
for(i=0;i<n;i++)
s[i]->getdata();
for(i=0;i<n;i++)
delete(s[i]);
return 0;

}




