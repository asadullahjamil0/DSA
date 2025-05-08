#include <iostream>

using namespace std;

void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int ptr = 0;
        while (ptr <= n - i)
        {
            if (A[ptr] > A[ptr + 1])
            {
                swap(A[ptr], A[ptr + 1]);
            }
            ptr++;
        }
    }
}

int main()
{
    int A[] = {30, 60, 50, 40, 10, 20};

    bubbleSort(A, 6);

    cout << "Sorted Array-> ";
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << ",";
    }
}