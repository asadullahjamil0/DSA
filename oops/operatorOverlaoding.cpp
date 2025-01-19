#include <iostream>
using namespace std;

class test
{
    int num;

public:
    test()
    {
        num = 0;
    }
    void operator++()
    {
        ++num;
    }
    void operator++(int)
    {
        num++;
    }
    void displayNum()
    {
        cout << "this is num:" << num << endl;
    }
    void operator--()
    {
        --num;
    }
    void operator--(int)
    {
        num--;
    }
};

int main()
{
    // built-in data types
    int n1;
    int n2;
    cout << n1 + n2 << endl;

    // user-defined data type which is not a correct way
    // test t1, t2;
    // cout << t1 + t2<<endl;

    test t1;
    ++t1;
    t1.displayNum();
    t1++;
    t1.displayNum();

    
    cout << "This is decrement in num!" << endl;
    --t1;
    t1.displayNum();
    t1--;
    t1.displayNum();
    // cout << "this is pre-fix" << ++t1;

    return 0;
}