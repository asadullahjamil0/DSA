#include <iostream>
using namespace std;

class Animal
{
    public:
    Animal()
    {
        cout << "Animal Constructor called!" << endl;
    }

    void Speak()
    {
        cout << "Animal is speaking" << endl;
    }
};

class Dog : public Animal
{
};

int main()
{
    Dog dg;
    dg.Speak();


    return 0;
}