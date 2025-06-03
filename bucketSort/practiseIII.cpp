#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    vector<float> buckets[n];

    // Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in buckets
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bucketSort(arr, n);

    cout << "\nSorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
