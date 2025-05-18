#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;

    // XOR all elements; duplicates cancel out
    for (int num : nums) {
        result ^= num;
    }

    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Single Number: " << singleNumber(nums) << endl;

    return 0;
}
