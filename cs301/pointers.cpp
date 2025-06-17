#include <iostream>
using namespace std;

void pointer_test()
{
    int x = 25;
    cout << "Value of x itself:" << x << endl;
    cout << "Address of x itself:" << &x << endl;

    int *p;
    p = &x;
    cout << "Value of address pointed to by p: " << *p << endl;
    cout << "Value of p itelf: " << p << endl;
}

void pointer_array_test()
{
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        nums[i] = i;
    }

    int *p;
    p = nums;
    cout << "Value of nums; " << nums << endl;
    cout << "Address of first element of nums: " << &nums[0] << endl;
    cout << "Value of p itself: " << p << endl;
    cout << "Value of address of p: " << *p << endl;

    cout << "Inc in p" << endl;
    p++;
    cout << "Value of p itself: " << p << endl;
    cout << "Value of address of p: " << *p << endl;

    cout << "Displaying all value of nums" << endl;
    p = &nums[0];
    for (int i = 0; i < 10; i++)
    {
        cout << "Value of p itself: " << p << " - ";
        cout << "Value of address of p: " << *p << " - ";
        cout << "Inc in p" << endl;
        p++;
    }
}

void null_pointer_test()
{
    int x = 25;

    int *p, *q;
    p = &x;
    q = NULL;

    cout << "Value of p itself: " << p << endl;
    cout << "Value of address of p: " << *p << endl;
    cout << "Value of p itself: " << q << endl;
    cout << "Value of address of p: " << *q << endl;
};

int main()
{
    // pointer_test();
    // pointer_array_test();
    null_pointer_test();
    return 0;
}