#include <iostream>
using namespace std;

#define n 5 // Set the size of the circular queue
class CircularQueue
{
    int *arr;
    int front;
    int back;

public:
    CircularQueue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    // Push an element to the queue
    void enqueue(int x)
    {
        if ((back + 1) % n == front)
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) // First element to be added
        {
            front = 0;
        }
        back = (back + 1) % n;
        arr[back] = x;
    }

    // Pop an element from the queue
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == back) // Only one element is left in the queue
        {
            front = back = -1; // Reset the queue
        }
        else
        {
            front = (front + 1) % n; // Move front pointer forward in circular manner
        }
    }

    // Get the front element of the queue
    int peek()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool empty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    CircularQueue qu;
    qu.enqueue(23);
    qu.enqueue(34);
    qu.enqueue(81);
    qu.enqueue(70);

    cout << "Is the queue empty? " << qu.empty() << endl;
    if (qu.empty() == 0)
    {
        cout << "Nahi line khaali nahi hy" << endl;
    }

    cout << "Front element: " << qu.peek() << endl; // Should output 23

    qu.dequeue();
    cout << "Front element after dequeue: " << qu.peek() << endl; // Should output 34

    qu.dequeue();
    qu.dequeue();
    qu.dequeue();

    // Check if queue is empty
    cout << "Is the queue empty? " << qu.empty() << endl; // Should output 1 (true)
    if (qu.empty() == 1)
    {
        cout << "hanji line khaali hy" << endl;
    }

    return 0;
}
