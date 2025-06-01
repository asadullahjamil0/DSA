#include <iostream>
#include <vector>
#include <algorithm>  // for sort()

using namespace std;

// Bucket Sort Function
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    vector<float> buckets[n];

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  // Index in bucket
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }
}

// Test the function
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bucketSort(arr, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
