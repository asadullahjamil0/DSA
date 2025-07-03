#include <iostream>
#include <vector>
#include <algorithm> // for sort()

using namespace std;

int main() {
    // Declare a vector of integers
    vector<int> numbers;

    // Add elements to the vector
    numbers.push_back(10);
    numbers.push_back(5);
    numbers.push_back(20);
    numbers.push_back(15);

    // Display the elements using a range-based for loop
    cout << "Original vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Access elements using index
    cout << "Element at index 2: " << numbers[2] << endl;

    // Modify an element
    numbers[1] = 8;
    cout << "After modifying index 1: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Remove the last element
    numbers.pop_back();
    cout << "After pop_back: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Insert an element at the beginning
    numbers.insert(numbers.begin(), 3);
    cout << "After insert at beginning: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Sort the vector
    sort(numbers.begin(), numbers.end());
    cout << "Sorted vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Clear all elements
    numbers.clear();
    cout << "Vector size after clear: " << numbers.size() << endl;

    return 0;
}
