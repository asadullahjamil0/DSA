#include <iostream>
#include <vector>
#include <algorithm> // for sort and find

using namespace std;

int main() {
    vector<int> numbers;

    // 1. Insert elements
    numbers.push_back(10);
    numbers.push_back(5);
    numbers.push_back(20);
    numbers.push_back(15);

    cout << "Original vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // 2. Access elements
    cout << "Element at index 2: " << numbers[2] << endl;

    // 3. Sort vector
    sort(numbers.begin(), numbers.end());

    cout << "Sorted vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // 4. Search for an element
    int key = 15;
    auto it = find(numbers.begin(), numbers.end(), key);
    if (it != numbers.end()) {
        cout << key << " found at index " << distance(numbers.begin(), it) << endl;
    } else {
        cout << key << " not found" << endl;
    }

    // 5. Remove last element
    numbers.pop_back();

    cout << "Vector after pop_back: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // 6. Erase element at index 1
    if (numbers.size() > 1) {
        numbers.erase(numbers.begin() + 1);
    }

    cout << "Vector after erasing index 1: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // 7. Clear the vector
    numbers.clear();
    cout << "Vector size after clear: " << numbers.size() << endl;

    return 0;
}
