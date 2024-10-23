#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[j + 1] + nums[i] == target)
            {
                ans.push_back(i);
                ans.push_back(j + 1);
                return ans;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = pairSum(nums, target);

    cout << "Your indices of pair sum is: " << ans[0] << " " << ans[1] << endl;

    return 0;
}