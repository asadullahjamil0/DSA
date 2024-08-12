#include <iostream>
using namespace std;

// void changeValue(int &z, int &y)
// {
//     z = 100;
//     y = 101;
// }

int sum(int a, int b = 0, int c = 0)
{
    return a + b + c;
}
int main()
{
    // Pass by value and pass by reference function
    // int a = 5;
    // int b = 6;
    // changeValue(a,b);
    // cout << a << "/" << b << endl;

    //Default parameters in function 
    cout << sum(23)<<endl;
    cout << sum(23,34)<<endl;
    cout << sum(23,34,56)<<endl;

    return 0;
}