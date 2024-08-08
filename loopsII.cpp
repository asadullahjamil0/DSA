#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number you want to check:";
    cin >> n;
    int digit = 0;
    while (n > 0)
    {
        digit++;
        n = n / 10;
    }
    cout << "The digits in your number are:" << digit << endl;

    return 0;
}