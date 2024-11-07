#include <iostream>
using namespace std;

class Product
{
private:
    int data;
    Product *next;
    int productId;

public:
    // Getters and Setters for data
    int getData() { return data; }
    void setData(int d) { data = d; }

    // Getters and Setters for productId
    int getProductId() { return productId; }
    void setProductId(int pId) { productId = pId; }

    // Get and set for next pointer
    Product *getNext() { return next; }
    void setNext(Product *nextNode) { next = nextNode; }
};

class Stack
{
private:
    Product *head;

public:
    Stack() : head(NULL) {}

    // Push an element onto the stack
    void push(int x)
    {
        Product *newNode = new Product();
        newNode->setData(x);
        newNode->setNext(head);
        head = newNode;
        cout << "Pushed digit " << x << " onto the stack.\n";
    }

    // Return the top element of the stack
    int top()
    {
        if (head != NULL)
        {
            return head->getData();
        }
        return -1; // Return -1 if stack is empty
    }

    // Pop the top element from the stack
    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty!\n";
            return -1; // Indicating stack is empty
        }
        int value = head->getData();
        Product *temp = head;
        head = head->getNext();
        delete temp;
        return value;
    }

    // Check if the stack is empty
    bool isEmpty() { return head == NULL; }
};

int main()
{
    Stack stack;
    int lastDigits = 12;
    int productId = 2400 + lastDigits;

    cout << "----------------------------------------\n";
    cout << "Product Id is: " << productId << "\n";
    cout << "------------------------\n";

    // Convert productId into an array of digits
    int id = productId;
    int array[4], i = 3;

    // Extract digits and store them in array
    while (id > 0)
    {
        int digit = id % 10;
        array[i--] = digit;
        id /= 10;
    }

    // Push digits onto the stack
    for (int i = 0; i <= 3; i++)
    {
        stack.push(array[i]);
    }

    // Print top element after pushing all digits
    cout << "\nThe top element of the stack is: " << stack.top() << "\n";
    cout << "-------------------------------------------\n";

    // Pop elements from the stack
    cout << "The first pop element of the stack is: " << stack.pop() << "\n";
    cout << "The second pop element of the stack is: " << stack.pop() << "\n";

    // Print top element after popping
    cout << "\nThe top element of the stack is: " << stack.top() << "\n";
    cout << "-------------------------------------------\n";

    return 0;
}
