
#include <iostream>
using namespace std;

class Product {
protected:
    int id;
    string title;
    double price;

public:
    Product(void) : id(1), title(""), price(0.0) {}
    

    virtual void Calculate_Price() = 0; 

    virtual void accept() {
        cout << "Enter ID : " << endl;
        cin >> id;
        cout << "Enter Title : " << endl;
        cin >> title;
        cout << "Enter Price : " << endl;
        cin >> price;
    }

    virtual void display() {
        cout << "ID is : " << id << endl;
        cout << "Title is : " << title << endl;
        cout << "Price is : " << price << endl;
    }

    double getPrice() const {
        return price;
    }
    virtual ~Product() {} 
};

class Book : public Product 
{
    private:
    string author;
public:
    Book(void) : author("") {}

    void accept() 
    {
        Product::accept();
        cout << "Enter author name : " << endl;
        cin >> author;
    }

    void Calculate_Price()
    {
        price = price - price * 0.1;
    }

    void display() 
    {
        Product::display();
        cout << "Author : " << author << endl;
    }
};

class Tape : public Product {
    private:
    string artist;
    public:
    Tape(void) : artist(" ") {}

    void Calculate_Price() {
        price = price - price * 0.05;
    }

    void accept() 
    {
        Product::accept();
        cout << "Enter the artist name" << endl;
        cin >> artist;
    }

    void display() 
    {
        Product::display();
        cout << "Artist : " << artist << endl;
    }
};

int main() 
{
    Product *arr[3] = {NULL, NULL, NULL}; 
    int count = 0;
    double total_amount = 0;
    int n = 1;

    while(n == 1) 
    { 
        int ch;
        cout << "1. Book" << endl;
        cout << "2. Tape" << endl;
        cout << "3. Display" << endl;
        cout << "4. Print Total Price " << endl;
        cout << "5. Exit " << endl;

        cout << "Enter choice : ";
        cin >> ch;

        switch(ch) 
        {
            case 1: 
                if(count < 3) {
                    arr[count] = new Book(); 
                    arr[count]->accept();
                    arr[count]->Calculate_Price();
                    total_amount += arr[count]->getPrice(); 
                    count++;
                } else {
                    cout << "Array is full" << endl;
                }
                break;
            
            case 2:
                if(count < 3) {
                    arr[count] = new Tape(); 
                    arr[count]->accept();
                    arr[count]->Calculate_Price();
                    total_amount += arr[count]->getPrice();
                    count++;
                } else {
                    cout << "Array is full" << endl;
                }
                break;

            case 3:
                for(int i = 0; i < count; i++) {
                    arr[i]->display();
                }
                break;
            
            case 4:
                cout << "Total Price : " << total_amount << endl;
                break;
            
            case 5:
                n = 0;
                break;     
        }
    }
    
    for(int i = 0; i < count; i++) {
        delete arr[i];
        arr[i] = NULL;
    }

    return 0;
}