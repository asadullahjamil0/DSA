#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A utility function to get the maximum value in an array
int getMax(const vector<int>& arr) {
    int mx = arr[0];
    for (int val : arr)
        if (val > mx)
            mx = val;
    return mx;
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to implement Radix Sort
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr);

    // Do counting sort for every digit (exp is 10^i)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

// Driver code
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);
    return 0;
}
