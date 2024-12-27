#include <iostream>
#include <string>
using namespace std;


class Employee {
protected:
    int empId;
    string empName;
    double salary;

public:
    Employee(int id, string name) : empId(id), empName(name), salary(0.0) {}
    virtual void calculateSalary() = 0;
    virtual void displaySalary() {
        cout << "Salary of " << empName << " is given below:\n";
        cout << salary << endl;
    }
    virtual ~Employee() {}
};


class RegularEmployee : public Employee {
private:
    double basicSalary;
    double allowances;
    double incomeTax;

public:
    RegularEmployee(int id, string name, double basic, double allow, double tax)
        : Employee(id, name), basicSalary(basic), allowances(allow), incomeTax(tax) {}

    void calculateSalary() override {
        salary = basicSalary + allowances - incomeTax;
    }

    void displaySalary() override {
        cout << "Salary of Regular Employee with basic pay: " << basicSalary
             << ", allowances: " << allowances
             << " and income tax: " << incomeTax << " is given below:\n";
        cout << salary << endl;
    }
};


class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int noOfHours;

public:
    HourlyEmployee(int id, string name, double rate, int hours)
        : Employee(id, name), hourlyRate(rate), noOfHours(hours) {}

    void calculateSalary() override {
        salary = hourlyRate * noOfHours;
    }

    void displaySalary() override {
        cout << "Salary of Hourly Employee with hourly rate: " << hourlyRate
             << " and no. of hours: " << noOfHours << " is given below:\n";
        cout << salary << endl;
    }
};

int main() {
    Employee* employees[2];


    employees[0] = new RegularEmployee(1, "John", 60000, 20000, 5000);

    employees[1] = new HourlyEmployee(2, "Jane", 3000, 20);


    for (int i = 0; i < 2; i++) {
        employees[i]->calculateSalary();
        employees[i]->displaySalary();
        cout << "---------------------------\n";
    }


    for (int i = 0; i < 2; i++) {
        delete employees[i];
    }

    return 0;
}