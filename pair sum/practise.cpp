#include <iostream>
using namespace std;

void findPair(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Pair found: " << arr[i] << " and " << arr[j] << endl;
                return;
            }
        }
    }
    cout << "No pair found." << endl;
}

int main() {
    int arr[] = {2, 7, 11, 15, 4, 8};
    int target = 26;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPair(arr, n, target);
    return 0;
}
