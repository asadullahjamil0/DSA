#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(vector<int> arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);

        // Reset currentSum if it drops below 0
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    int result = kadane(arr);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
