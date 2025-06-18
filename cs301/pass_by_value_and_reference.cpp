#include <iostream>
using namespace std;

void first_function(int v)
{
    v = v + 10;
    cout << "Address of v inside the first function: " << &v << endl;
    cout << "Value of v inside the first function: " << v << endl;
}

void second_function(int &v)
{
    v = v + 10;
    cout << "Address of v inside the second function: " << &v << endl;
    cout << "Value of v inside the second function: " << v << endl;
}

void runner()
{
    int x = 0;
    cout << "Addres of x: " << &x << endl;
    cout << "Value of x first step: " << x << endl;

    first_function(x);
    cout << "Value of x second step: " << x << endl;

    second_function(x);
    cout << "Value of x third step: " << x << endl;
}

void test_array(int b[], int size)
{
    cout << "Address of b: " << b << endl;
    cout << "Elements of an array b -> ";
    for (int i = 0; i < size; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    b[0] = 24;
}

void value_as_args()
{
    int a[5] = {0, 1, 2, 3, 4};
    test_array(a, 5);

    cout << "Address of a: " << a << endl;
    cout << "Elements of an array a -> ";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}

void struct_test()
{
    struct student
    {
        int rollNo;
        float marks;
    };

    student s1;
    s1.rollNo = 13;
    s1.marks = 23.5;

    cout <<"\ns1.marks  = " << s1.marks << endl;
    student *sPtr;
    sPtr = &s1;
    cout << "(*sPtr).marks   = " << (*sPtr).marks << endl;

    // (*sPtr).marks  =  sPtr->marks
    cout << "sPtr -> marks" << sPtr->marks << endl;
}

int main()
{
    runner();
    value_as_args();
    struct_test();

    return 0;
}