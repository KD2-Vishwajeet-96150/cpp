#include<stdio.h>

struct Date {
    int day;
    int month; 
    int year;
};

void initDate(struct Date* ptrDate){
    ptrDate->day=1;
    ptrDate->month=1;
    ptrDate->year=2000;

};

void printDateOnConsole(struct Date* ptrDate){
         printf("Day: %d\n", ptrDate->day);
         printf("Month: %d\n", ptrDate->month);
         printf("Year: %d\n", ptrDate->year);
         
};

void acceptDateFromConsole(struct Date* ptrDate){
printf("Day: ");     
scanf("%d",&ptrDate->day);


printf("Month: ");
scanf("%d", &ptrDate->month);

printf("year: ");
scanf("%d", &ptrDate->year);

};

int menuList( void )
{
    int choice; 
    printf("0.Exit.\n"); 
    printf("press 1 to initialize date \n"); 
    printf("press 2 to print date\n");
    printf("press 3 to accept date\n ");
    printf("Enter the choice:");
    scanf("%d",&choice); 
    return choice; 
}

int main(){
    struct Date d;
    int choice;
    while((choice=menuList())!=0){
        switch (choice)
        {
        case 1: 
           initDate(&d); 
            break;

        case 2: 
            printDateOnConsole(&d); 
            break;
             
        case 3:
            acceptDateFromConsole(&d);
            break;
            
        }
    }
}