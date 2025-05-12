#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // To find sub-arrays in an array
    // int arr[5] = {1, 2, 3, 4, 5};
    // int n = 5;
    // for (int st = 0; st < n; st++)
    // {
    //     for (int end = st; end < n; end++)
    //     {
    //         for (int i = st; i <= end; i++)
    //         {
    //             cout << arr[i];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    // To find maximum sub-Array
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};
    int n = 7;

    // int maxSum = INT_MIN;
    // for (int st = 0; st < n; st++)
    // {
    //     int currentSum = 0;
    //     for (int end = st; end < n; end++)
    //     {
    //         currentSum += arr[end];
    //         maxSum = max(currentSum, maxSum);
    //     }
    // }

    // Same approach by kadane's algorithm
    int maximumSum = INT_MIN;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        maximumSum = max(currentSum, maximumSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    cout << "Sum of maximum sub-array is: " << maximumSum << endl;

    return 0;
}