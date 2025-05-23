#include <iostream>
#include <vector>
#include <algorithm> // For max_element
using namespace std;

// Function to perform counting sort
void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum element in the array
    int max_val = *max_element(arr.begin(), arr.end());

    // Create a count array to store the frequency of each element
    vector<int> count(max_val + 1, 0);

    // Count the occurrences of each element
    for (int num : arr) {
        count[num]++;
    }

    // Overwrite the original array with sorted elements
    int index = 0;
    for (int i = 0; i <= max_val; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Main function to test counting sort
int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted array:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
