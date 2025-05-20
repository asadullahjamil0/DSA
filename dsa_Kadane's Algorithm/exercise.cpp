#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to implement Kadane's Algorithm
int kadane(vector<int> arr) {
    int maxSum = INT_MIN; // Initialize with the smallest integer
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];             // Add current element to currentSum
        maxSum = max(maxSum, currentSum); // Update maxSum if needed

        if (currentSum < 0) {
            currentSum = 0; // Reset if currentSum becomes negative
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr;
    int n;

    cout << "=== Kadane's Algorithm Exercise ===\n";
    cout << "Enter number of elements in the array: ";
    cin >> n;

    cout << "Enter " << n << " integer values:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        arr.push_back(value);
    }

    int maxSubarraySum = kadane(arr);
    cout << "Maximum subarray sum is: " << maxSubarraySum << endl;

    return 0;
}
