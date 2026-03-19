#include<iostream>
using namespace std;

class Time{

private:
    int hrs;
    int min;
    int sec;

public:
      
    Time(void) : hrs(0), min(0), sec(0)
    { }

    Time(int hrs, int min, int sec) : hrs(hrs), min(min), sec(sec)
    { }

    void printTime(void)
    {
        cout<<hrs<<":"<<min<<":"<<sec<<endl;
    }

    void setHrs(int hrs)
    {
        this->hrs = hrs;
    }

    void setMin(int min)
    {
        this->min = min;
    }
    
    void setSec(int sec)
    {
        this->sec = sec;
    }

    int getHrs()
    {
        return hrs;
    }
};

int menuList()
{
    int choice;
    cout<<"\n0. EXIT"<<endl;
    cout<<"1. Add Time"<<endl;
    cout<<"2. Display All Time"<<endl;
    cout<<"3. Display only hrs of all time objects"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    int size;
    int index = 0;

    cout<<"Enter the array size : ";
    cin>>size;

    Time *arr = new Time[size];

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
                if(index < size)
                {
                    int hrs, min, sec;

                    cout<<"HOUR : ";
                    cin>>hrs;

                    cout<<"MINUTE : ";
                    cin>>min;

                    cout<<"SECOND : ";
                    cin>>sec;

                    arr[index].setHrs(hrs);
                    arr[index].setMin(min);
                    arr[index].setSec(sec);

                    index++;
                }
                else
                {
                    cout<<"Array Full!"<<endl;
                }
                break;
            }

            case 2:
            {
                if(index == 0)
                {
                    cout<<"No Time objects stored yet!"<<endl;
                }
                else
                {
                    cout<<"All Time Objects:"<<endl;
                    for(int i=0;i<index;i++)
                    {
                        arr[i].printTime();
                    }
                }
                break;
            }

            case 3:
            {
                if(index == 0)
                {
                    cout<<"No Time objects stored yet!"<<endl;
                }
                else
                {
                    cout<<"Only Hours:"<<endl;
                    for(int i=0;i<index;i++)
                    {
                        cout<<arr[i].getHrs()<<endl;
                    }
                }
                break;
            }

            default:
                cout<<"Invalid Choice"<<endl;
        }
    }

    delete[] arr;

    cout<<"Program Ended"<<endl;

    return 0;
}

