#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count(maxVal + 1, 0);

    for (int num : arr) {
        count[num]++;
    }

    for (int i = 1; i <= maxVal; ++i) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    arr = output;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);

    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
