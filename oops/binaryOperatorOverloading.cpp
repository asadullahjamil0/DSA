#include <iostream>
using namespace std;

class Test
{
    int num;

public:
    Test(int n)
    {
        num = n;
    }
    Test operator+(Test t2)
    {
        Test t3(0);
        t3 = num + t2.num;
        return t3;
    }
    Test operator-(Test t2)
    {
        Test t3(0);
        t3 = num - t2.num;
        return t3;
    }
    Test operator*(Test t2)
    {
        Test t3(0);
        t3 = num * t2.num;
        return t3;
    }
    Test operator/(Test t2)
    {
        Test t3(0);
        t3 = num / t2.num;
        return t3;
    }

    void getNum()
    {
        cout << num << endl;
    }
};

int main()
{
    Test t1(60);
    Test t2(20);
    Test sum(0);

    cout << "This is addition:";
    sum = t1 + t2;
    sum.getNum();

    cout << "This is subtraction:";
    sum = t1 - t2;
    sum.getNum();
    cout << "This is division:";
    sum = t1 / t2;
    sum.getNum();
    cout << "This is mulitplication:";
    sum = t1 * t2;
    sum.getNum();

    // t1.getNum();

    return 0;
}