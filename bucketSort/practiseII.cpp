#include <iostream>
#include <vector>
#include <algorithm> // for sort()
using namespace std;

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    vector<float> buckets[n];

    // 2. Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // 4. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < buckets[i].size(); j++)
            arr[index++] = buckets[i][j];
}

// Driver code
int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
