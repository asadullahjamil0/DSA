#include <iostream>
#include <vector>

using namespace std;

int majElements(vector<int> nums)
{
    int n = nums.size();
    for (int val : nums)
    {
        int count = 0;
        for (int el : nums)
        {
            if (val == el)
            {
                count++;
            }
        }
        if (count > (n / 2))
        {
            return val;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {8, 8, 7, 7, 7};
    cout << "Majority Element is: " << majElements(nums) << endl;

    return 0;
}