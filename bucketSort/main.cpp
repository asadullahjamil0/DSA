#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

// Bucket sort function
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    vector<float> buckets[n];

    // 1. Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in the range [0, n-1]
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 2. Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // 3. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            arr[index++] = buckets[i][j];
}

// Utility function to print an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function to test the algorithm
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "\nSorted array:\n";
    printArray(arr, n);

    return 0;
}
