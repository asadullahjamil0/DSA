#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed onto stack" << endl;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow! Cannot pop from empty stack." << endl;
            return -1;
        } else {
            int popped_value = arr[top--];
            return popped_value;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);

    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    stack.display();

    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
