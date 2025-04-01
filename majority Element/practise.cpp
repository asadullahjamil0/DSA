#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;

    // Boyer-Moore Voting Algorithm
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    
    cout << "Majority Element: " << majorityElement(nums) << endl;

    return 0;
}
