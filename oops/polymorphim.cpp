#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual double area() = 0;
    virtual void display() {
        cout << "This is a shape." << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}


    double area() override {
        return length * width;
    }

    void display() override {
        cout << "This is a rectangle." << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return M_PI * radius * radius;
    }

    void display() override {
        cout << "This is a circle." << endl;
    }
};

int main() {
    Shape* shape1 = new Rectangle(5.0, 3.0);
    Shape* shape2 = new Circle(4.0);

    shape1->display();
    cout << "Area: " << shape1->area() << " square units" << endl;

    shape2->display();
    cout << "Area: " << shape2->area() << " square units" << endl;

    delete shape1;
    delete shape2;

    return 0;
}
