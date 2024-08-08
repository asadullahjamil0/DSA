#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number for factorial:";
    cin >> n;
    int digitSum = 1;
    for (int i = 1; i <= n; i++)
    {
        digitSum *= i;
        cout << "The factorial of number is:" << digitSum << endl;
    }

    return 0;
}