#include <iostream>
#include <string>
#include<typeinfo>
using namespace std;

// Base Class: Employee
class Employee {
private:
    int id;
    double salary;
public:
    Employee() : id(0), salary(0.0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}
    
    void setId(int id) { this->id = id; }
    int getId() { return id; }
    void setSalary(double salary) { this->salary = salary; }
    double getSalary() { return salary; }

    virtual void accept() {
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Salary: "; cin >> salary;
    }

    virtual void display() {
        cout << "ID: " << id << ", Salary: " << salary;
    }

    virtual ~Employee() {} 
};

class Manager : virtual public Employee {
private:
    double bonus;
protected:
    void acceptManager() {
        cout << "Enter Bonus: "; cin >> bonus;
    }
    void displayManager() {
        cout << ", Bonus: " << bonus;
    }
public:
    Manager() : bonus(0.0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus) { this->bonus = bonus; }
    double getBonus() { return bonus; }

    void accept() override {
        Employee::accept();
        acceptManager();
    }

    void display() override {
        Employee::display();
        displayManager();
    }
};

class Salesman : virtual public Employee {
private:
    double commission;
protected:
    void acceptSalesman() {
        cout << "Enter Commission: "; cin >> commission;
    }
    void displaySalesman() {
        cout << ", Commission: " << commission;
    }
public:
    Salesman() : commission(0.0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void setCommission(double commission) { this->commission = commission; }
    double getCommission() { return commission; }

    void accept() override {
        Employee::accept();
        acceptSalesman();
    }

    void display() override {
        Employee::display();
        displaySalesman();
    }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() {}
    SalesManager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void accept() override {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display() override {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main() {
    int choice;
    const int MAX = 100;
    Employee* employees[MAX];
    int count = 0;

    int mCount = 0, sCount = 0, smCount = 0;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Add Manager\n2. Add Salesman\n3. Add Salesmanager\n4. Display Counts\n";
        cout << "5. Display Managers\n6. Display Salesmen\n7. Display SalesManagers\n0. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (count < MAX) {
                    employees[count] = new Manager();
                    employees[count]->accept();
                    count++; mCount++;
                }
                break;
            case 2:
                if (count < MAX) {
                    employees[count] = new Salesman();
                    employees[count]->accept();
                    count++; sCount++;
                }
                break;
            case 3:
                if (count < MAX) {
                    employees[count] = new SalesManager();
                    employees[count]->accept();
                    count++; smCount++;
                }
                break;
            case 4:
                cout << "Managers: " << mCount << "\nSalesmen: " << sCount << "\nSalesManagers: " << smCount << endl;
                break;
            case 5:
                for (int i = 0; i < count; i++) {
                    if (typeid(*employees[i]) == typeid(Manager)) {
                        employees[i]->display(); cout << endl;
                    }
                }
                break;
            case 6:
                for (int i = 0; i < count; i++) {
                    if (typeid(*employees[i]) == typeid(Salesman)) {
                        employees[i]->display(); cout << endl;
                    }
                }
                break;
            case 7:
                for (int i = 0; i < count; i++) {
                    if (typeid(*employees[i]) == typeid(SalesManager)) {
                        employees[i]->display(); cout << endl;
                    }
                }
                break;
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++) delete employees[i];

    return 0;
}








        








