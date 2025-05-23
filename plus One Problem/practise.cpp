#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    
    // If all digits were 9, we need an extra digit
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits = {9, 9, 9}; // Example input

    vector<int> result = plusOne(digits);

    cout << "Result: ";
    for (int num : result) {
        cout << num;
    }
    cout << endl;

    return 0;
}
