#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int idx = digits.size() - 1;
    for (int val : digits)
    {
        if (val == 9)
        {
            digits[idx] = 0;
        }
        else
        {
            digits[idx] += 1;
            return digits;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{
    vector<int> digits = {9};
    vector<int> ans = plusOne(digits);

    cout << ans[1];

    return 0;
}