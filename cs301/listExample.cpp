#include <iostream>
#include <list>  // Include the list header from the STL
using namespace std;

int main() {
    // Create a list of integers
    list<int> myList;

    // Add some elements to the list
    myList.push_back(10); // Insert 10 at the end
    myList.push_back(20); // Insert 20 at the end
    myList.push_back(30); // Insert 30 at the end
    myList.push_back(40); // Insert 40 at the end
    myList.push_back(50); // Insert 50 at the end

    // Display the list before removal
    cout << "Original list:" << endl;
    for (int val : myList) {
        cout << val << " "; // Traverse and print the list
    }
    cout << endl;

    // Remove a specific value (e.g., remove 30 from the list)
    myList.remove(30);
    cout << "After removing 30:" << endl;
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // Insert an element at the beginning of the list
    myList.push_front(5);
    cout << "After inserting 5 at the front:" << endl;
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // Insert an element in the middle (before element 40)
    auto it = myList.begin();
    advance(it, 3); // Move iterator to the 4th element (before 40)
    myList.insert(it, 35);
    cout << "After inserting 35 before 40:" << endl;
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // Traverse the list in reverse order using a reverse iterator
    cout << "List in reverse order:" << endl;
    for (auto rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
