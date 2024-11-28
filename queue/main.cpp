#include <iostream>
using namespace std;

#define n 100
class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Array is full" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (back == -1 || front > back)
        {
            cout << "No element to pop" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (back == -1 || front > back)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (back == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue qu;
    qu.push(23);
    qu.push(34);
    qu.push(81);
    qu.push(70);
    cout << qu.peek() << endl;
    qu.pop();
    cout << qu.peek() << endl;

    return 0;
}