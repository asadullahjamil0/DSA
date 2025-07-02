#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> numbers;

    // Add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements using indexing
    std::cout << "First element: " << numbers[0] << std::endl;

    // Access elements using at() - with bounds checking
    std::cout << "Second element: " << numbers.at(1) << std::endl;

    // Iterate over the vector using a range-based for loop
    std::cout << "All elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Check the size of the vector
    std::cout << "Vector size: " << numbers.size() << std::endl;

    // Remove the last element
    numbers.pop_back();

    // After pop_back
    std::cout << "After pop_back, size: " << numbers.size() << std::endl;

    // Resize the vector to 5 elements, new elements will be 0
    numbers.resize(5);

    // Print resized vector
    std::cout << "After resize to 5 elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
