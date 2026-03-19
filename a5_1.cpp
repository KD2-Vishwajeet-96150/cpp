 #include<iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void acceptDate()
    {
        cout<<"Enter Day : ";
        cin>>day;
        cout<<"Enter Month : ";
        cin>>month;
        cout<<"Enter Year : ";
        cin>>year;
    }

    void displayDate()
    {
        cout<<day<<":"<<month<<":"<<year;
    }
};

class Person
{
private:
    string name;
    string address;
    Date dob;

public:
    void acceptPerson()
    {
        cout<<"Enter Name : ";
        cin.ignore();              // clear buffer
        getline(cin, name);

        cout<<"Enter Address : ";
        getline(cin, address);

        cout<<"Enter Date of Birth:"<<endl;
        dob.acceptDate();
    }

    void displayPerson()
    {
        cout<<"\n--- Person Details ---"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Address : "<<address<<endl;
        cout<<"Date of Birth : ";
        dob.displayDate();
        cout<<endl;
    }
};

class Student
{
private: 
    int id;
    int marks;
    string course;
    Date join_dt;
    Date end_dt;

public:
    void acceptStudent()
    {
        cout<<"\nEnter ID : ";
        cin>>id;

        cout<<"Enter Marks : ";
        cin>>marks;

        cout<<"Enter Course : ";
        cin>>course;

        cout<<"Enter Join Date:"<<endl;
        join_dt.acceptDate();

        cout<<"Enter End Date:"<<endl;
        end_dt.acceptDate();
    }

    void displayStudent()
    {
        cout<<"\n--- Student Details ---"<<endl;
        cout<<"ID : "<<id<<endl;
        cout<<"Marks : "<<marks<<endl;
        cout<<"Course : "<<course<<endl;

        cout<<"Join Date : ";
        join_dt.displayDate();
        cout<<endl;

        cout<<"End Date : ";
        end_dt.displayDate();
        cout<<endl;
    }
};

int main()
{
    Person p;
    Student s;

    cout<<"Enter Person Details"<<endl;
    p.acceptPerson();

    cout<<"\nEnter Student Details"<<endl;
    s.acceptStudent();

    cout<<"\nDisplaying Details..."<<endl;

    p.displayPerson();
    s.displayStudent();

    return 0;
}