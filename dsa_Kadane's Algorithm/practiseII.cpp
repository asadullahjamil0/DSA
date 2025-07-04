#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadaneMaxSubarraySum(const vector<int>& nums) {
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;

    for (int i = 0; i < nums.size(); i++) {
        maxEndingHere += nums[i];

        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;

        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }

    return maxSoFar;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    int maxSum = kadaneMaxSubarraySum(arr);
    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}
