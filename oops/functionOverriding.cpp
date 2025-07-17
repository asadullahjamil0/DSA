#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    // Virtual function - can be overridden
    virtual void makeSound() {
        cout << "The animal makes a sound." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // Override the base class function
    void makeSound() override {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Animal a;       // Base class object
    Dog d;          // Derived class object

    Animal* ptr;    // Base class pointer

    ptr = &a;
    ptr->makeSound();  // Calls Animal's version

    ptr = &d;
    ptr->makeSound();  // Calls Dog's overridden version due to virtual function

    return 0;
}
