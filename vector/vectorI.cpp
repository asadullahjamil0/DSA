#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Vector in c++
    vector<string> cars = {"BMW", "Toyota", "Rolls Roycce", "Honda", "Mercedes"};
    cout << "First element of cars is " << cars.front() << endl;
    cout << "Last element of cars is " << cars.back() << endl;
    cars.push_back("Ferrari");
    cout << "New added element is " << cars.at(5) << endl;
    cout << "Before removing last element size of an array is: " << cars.size() << endl;
    cars.pop_back();
    cout << "Now after removing size of an array is: " << cars.size() << endl;
    // also we can print all the value of an array
    for (string i : cars)
    {
        cout << i << endl;
    }
    // we can also change the value of element
    cars[2] = "Suzuki";
    cout << "Now the value at index 2 is " << cars[2] << endl;
    // we can also check if the vector is empty or not it returns 1 if empty otherwise 0
    vector<int> vec = {};
    cout << cars.empty() << endl;
    cout << vec.empty() << endl;
    // we can aslo print the values by for loop
    for (int i = 0; i < cars.size(); i++)
    {
        cout << cars[i] << endl;
    }
    // to size and capacity of empty vector
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    // Problem to find single number
    vector<int> singleNum = {4, 1, 2, 1, 2, 3, 5, 3, 5};
    int sum = 0;
    for (int i : singleNum)
    {
        sum = sum ^ i;
    }
    cout << "Single number of an array is: " << sum << endl;

    return 0;
}