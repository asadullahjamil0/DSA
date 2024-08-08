#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter number n and m:";
    cin >> n >> m;
    int result = 1;
    for (int i = 1; i <= m; i++)
    {
        result *= n;
    }
    cout << "The n to the power m is:" << result << endl;

    return 0;
}