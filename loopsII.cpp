#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number you want to add:";
    cin >> n;
    int digitSum = 0;
    int digits;
    while (n > 0)
    {
        digits = n % 10;
        digitSum += digits;
        n /= 10;
    }
    cout << "The sum of your number is:" << digitSum << endl;

    return 0;
}