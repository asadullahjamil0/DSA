#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

int main()
{
    // printf("INT MAX:", INT32_MIN);
    cout << endl
         << "INT MAX:" << INT64_MAX << endl;

    // For integer value in 32 bit machine
    // int x = 2147483648;
    // cout << "MAx Num: " << x << endl;

    // For integer value in 64 bit machine
    long long y = 9223372036854775807;
    cout << "MAx Num: " << y << endl;

    char x = 'z';
    cout << "Value of variable x: " << x << endl;
    cout << "Converted to int: " << (int)x << endl;
    cout << "Adding 1 = " << (char)(x + 1) << endl;

    return 0;
}