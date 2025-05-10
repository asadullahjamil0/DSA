#include <iostream>
using namespace std;

void bubbleSort(int numbers[], int size)
{
    for (int pass = 0; pass < size - 1; pass++)
    {
        int index = 0;
        while (index < size - pass - 1)
        {
            if (numbers[index] > numbers[index + 1])
            {
                swap(numbers[index], numbers[index + 1]);
            }
            index++;
        }
    }
}

int main()
{
    int data[] = {88, 33, 22, 77, 11, 99, 81, 74};
    int length = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, length);

    cout << "Sorted values: ";
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}
