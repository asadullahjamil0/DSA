#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majElements(vector<int> nums)
{
    // Simple approach to solve that problem
    //  int n = nums.size();
    //  for (int val : nums)
    //  {
    //      int count = 0;
    //      for (int el : nums)
    //      {
    //          if (val == el)
    //          {
    //              count++;
    //          }
    //      }
    //      if (count > (n / 2))
    //      {
    //          return val;
    //      }
    //  }

    // Brute-Force approach to soleve that provlem
    // Sort method is used for sorting an array
    // sort(nums.begin(), nums.end());
    // int freq = 1, ans = nums[0];
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     if (nums[i] == nums[i - 1])
    //     {
    //         freq++;
    //     }
    //     else
    //     {
    //         freq = 1, ans = nums[i];
    //     }
    //     if (freq > (nums.size() / 2))
    //     {
    //         return ans;
    //     }
    // }

    // More Optimized approach to solve this problem which is moore's
    int freq = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 3, 3, 3, 1, 1, 1};
    cout << "Majority Element is: " << majElements(nums) << endl;

    return 0;
}