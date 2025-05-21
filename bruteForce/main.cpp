#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    bool found = false;

    // Brute-force search
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = true;
            cout << "Number found at index " << i << endl;
            break;
        }
    }

    if (!found) {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
