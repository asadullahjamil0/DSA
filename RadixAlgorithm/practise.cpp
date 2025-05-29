#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum value in the array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// A function to do counting sort based on a specific digit (exp = 1, 10, 100, etc.)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Transform count[] so it contains actual positions of digits in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (go backwards for stability)
    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    // Copy the output array back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main Radix Sort function
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Apply counting sort for each digit, from least significant to most
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "\nSorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
