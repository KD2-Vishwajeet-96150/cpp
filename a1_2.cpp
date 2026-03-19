 #include<iostream>
 using namespace std;

 struct Date {
   
    int day;
    int month;
    int year;

 

void initDate(){
     day=1;
     month=1;
     year=2000;


    };

void printDateOnConsole(){

          cout << "date: "<< day<<"/"
               << month << "/"
               << year << endl;
            
 };

void acceptDateFromConsole(){
            cout << "Enter Day: ";
            cin >> day;

            cout << "Enter Month: ";
            cin >> month;

            cout << "Enter Year: ";
            cin >> year;
           
            };



 bool isLeapYear(){
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
         
};

int menuList(){
    int choice;
      cout<< "0.Exit.\n"; 
      cout<< "press 1 to initialize date \n"; 
      cout<< "press 2 to print date\n";
      cout<< "press 3 to accept date\n ";
      cout<< "Enter the choice:";
      cout<< "%d",&choice; 
    return choice;

};


int main(){
    int choice;
    Date d;

    while((choice=menuList())!=0){


        switch (choice){
      case 1:
            d.initDate();
            break;
       case 2: 
            d.printDateOnConsole();
            break;

       case 3:
            d.acceptDateFromConsole();
            break;

        case 4:
            d.isLeapYear();
            break;

                 
        }

    }
}