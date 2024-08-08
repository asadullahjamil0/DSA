#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number you want to reverse:";
    cin >> n;
    int digitSum = 0;
    int digits;
    while (n > 0)
    {
        digits = n % 10;
        digitSum = (digitSum * 10) + digits;
        n /= 10;
    }
    cout << "The reverse of your number is:" << digitSum << endl;

    return 0;
}