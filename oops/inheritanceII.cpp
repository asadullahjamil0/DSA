#include <iostream>
using namespace std;

class Employee
{
    float salary;

public:
    int id;
    Employee(int inpId)
    {
        id = inpId;
        salary = 40.2389;
    }
    Employee() {}
};

class Programmer : public Employee
{
public:
    Programmer(int inpId)
    {
        id = inpId;
    }
    int languageCode = 9;
    void getData()
    {
        cout << id << endl;
    }
};
int main()
{
    Employee emp1(23);
    cout << emp1.id << endl;
    Programmer prog(34);
    cout << prog.languageCode << endl;
    cout << prog.id << endl;
    prog.getData();

    return 0;
}