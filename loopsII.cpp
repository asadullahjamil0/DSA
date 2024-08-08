#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number you want to check:";
    cin >> n;
    int digitSum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            digitSum -= i;
        }
        else
        {
            digitSum += i;
        }
    }

    cout << "The final number is:" << digitSum << endl;

    return 0;
}