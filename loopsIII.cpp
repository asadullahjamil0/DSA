#include <iostream>

int main() {
    // Outer loop for rows (1 to 10)
    for (int i = 1; i <= 10; i++) {
        // Inner loop for columns (1 to 10)
        for (int j = 1; j <= 10; j++) {
            // Calculate and print the product of i and j
            std::cout << i * j << "\t";  // '\t' is used to add a tab space for better alignment
        }
        std::cout << std::endl;  // Move to the next line after each row is printed
    }

    return 0;
}
