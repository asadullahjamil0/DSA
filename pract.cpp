#include <iostream>
using namespace std;

// Function to calculate the average of an array
double calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;  // Cast to double for accurate average
}

int main() {
    // Define an array of integers
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Calculate array size

    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Calculate and print the average of the numbers
    double avg = calculateAverage(numbers, size);
    cout << "The average of the array is: " << avg << endl;

    // Conditional check to see if the average is above a threshold
    if (avg > 25) {
        cout << "The average is above 25!" << endl;
    } else {
        cout << "The average is 25 or below." << endl;
    }

    // Loop to demonstrate simple counting
    cout << "Counting from 1 to 5: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
