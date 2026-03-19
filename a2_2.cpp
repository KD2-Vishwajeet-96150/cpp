
#include<iostream>
using namespace std;


class TollBooth{

    private:
    unsigned int carsCount;
    double totalMoney;
    unsigned int payingCars;
    unsigned int nonPayingCars;


    public:
    TollBooth(void){
        carsCount=0;
        totalMoney=0;
        payingCars=0;
        nonPayingCars=0;
    }


    void payingCar(){
        ++carsCount;
        totalMoney = totalMoney + 0.50;
        ++payingCars;

    }

    void nopayCar(){

        ++carsCount;
        ++nonPayingCars;

    }

    void printOnConsole(){
        cout << "No. of cars gone by : "<< carsCount <<endl;
        cout << "Total amount collected: "<< totalMoney << endl;
        cout << "paying Cars: "<< payingCars << endl;
        cout << "non paying cars: "<< nonPayingCars << endl;

    }
  

};

int menuList(){
    int choice;
    cout<<"enter 0 to exit "<<endl;
    cout<<"enter 1 to to add paying car"<<endl;
    cout<<"enter 2 to add nonpaying car"<<endl;
    cout<<"enter 3 to display cars gone by and Total amount collected"<<endl;

    cin>>choice;

    return choice; 

}


int main(){

    int choice;
    TollBooth t;

    while((choice=menuList())!=0){
        switch(choice) {
            
            case 1 : t.payingCar();
            break;

            case 2 : t.nopayCar();
            break;
        
            case 3 : t.printOnConsole();
          }
    }




}