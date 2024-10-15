#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Create a vector to hold integers
    vector<int> numbers;

    // Add some elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    // Display the elements in the vector
    cout << "Elements in the vector: ";
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Display the size of the vector
    cout << "Size of the vector: " << numbers.size() << endl;

    // Remove the last element
    numbers.pop_back();

    // Display the elements again
    cout << "Elements after pop_back: ";
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
