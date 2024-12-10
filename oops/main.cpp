#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;
    string fatherName;

public:
    Person()
    {
        cout << "Non-Paramterized Constructor called...\n";
    }
    Person(string name)
    {
        this->name = name;
        cout << "Paramterized Constructor called...\n";
    }

    void setInfo(int age, string fatherName)
    {
        this->age = age;
        this->fatherName = fatherName;
    }
    void getInfo()
    {
        cout << "Age: " << age << endl;
        cout << "Father's name: " << fatherName << endl;
    }
    void Hello()
    {
        cout << "Hello from Parent class!" << endl;
    }
};

class Child : public Person
{
public:
    void Hello()
    {
        cout << "Hello from Child class!" << endl;
    }
};

 void counter()
    {
        static int x = 0;
        cout << "x: " << x << endl;
        x++;
    }

int main()
{
    Person p2("AsadUllah!");
    Person p1;
    p1.setInfo(56, "Muhammad Jamil");
    p1.getInfo();

    Child c1;
    c1.Hello();
    p1.Hello();

    counter();
    counter();
    counter();

    return 0;
}