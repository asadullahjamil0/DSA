#include <iostream>
#include <list> // Use the correct STL list header
using namespace std;

int main()
{
    list<int> ist; // Declare a list of integers
    ist.push_back(12);
    ist.push_back(34);
    ist.push_back(53);
    ist.push_back(19);
    ist.push_back(94);
    ist.remove(94);

    auto it = ist.begin();
    // Use an iterator to traverse the list
    while (it != ist.end())
    {
        cout << "List element: " << *it << endl; // Dereference the iterator to get the value
        it++;
    }

    return 0;
}
