#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Step 1: Find the maximum element
    int maxElement = *max_element(arr.begin(), arr.end());

    // Step 2: Create and initialize count array
    vector<int> count(maxElement + 1, 0);

    // Step 3: Count occurrences of each element
    for (int num : arr) {
        count[num]++;
    }

    // Step 4: Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i]-- > 0) {
            arr[index++] = i;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    
    cout << "Original array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
