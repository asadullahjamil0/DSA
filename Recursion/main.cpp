#include <iostream>//
using namespace std;
int Sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int previous = Sum(n - 1);
    return n + previous;
}

int Power(int k, int p)
{
    if (p == 0)
    {
        return 1;
    }
    int previousPower = Power(k, p - 1);
    return k * previousPower;
}

int factorial(int f)
{
    if (f == 0)
    {
        return 1;
    }
    return f * factorial(f - 1);
}
int fabonacci(int i)
{
    if (i == 0 || i == 1)
    {
        return i;
    }
    return fabonacci(i - 1) + fabonacci(i - 2);
}

int main()
{
    int n, p, k, f, i;
    cout << "Enter Number to Fabonacci sum:";
    cin >> i;
    cout << fabonacci(i) << endl;
    cout << "Enter Number to calculate sum:";
    cin >> n;
    cout << Sum(n) << endl;
    cout << "Enter Number and power to calculate Power:";
    cin >> k >> p;
    cout << Power(k, p) << endl;
    cout << "Enter Number to calculate Factorial:";
    cin >> f;
    cout << factorial(f) << endl;
    cout << factorial(f) << endl;
    return 0;
}
