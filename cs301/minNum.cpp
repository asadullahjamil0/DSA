#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 2, 9, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    cout << "Minimum number is: " << min << endl;
    return 0;
}
