#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char value) : data(value), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(char value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        Node *temp = top;
        char value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    char peek()
    {
        return isEmpty() ? '\0' : top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

bool isBalanced(const string &input)
{
    Stack stack;

    for (char ch : input)
    {

        if (ch != '(' && ch != ')' && ch != '{' && ch != '}' && ch != '[' && ch != ']')
        {
            cout << "Wrong input: only brackets are allowed." << endl;
            return false;
        }

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
        }
        else
        {
            if (stack.isEmpty())
            {
                cout << "Brackets are not balanced." << endl;
                return false;
            }

            char top = stack.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
            {
                cout << "Brackets are not balanced." << endl;
                return false;
            }
        }
    }

    if (!stack.isEmpty())
    {
        cout << "Brackets are not balanced." << endl;
        return false;
    }

    cout << "The brackets are balanced." << endl;
    return true;
}

int main()
{
    string input;
    cout << "My VUID is BC~Scammer404" << endl;
    cout << "Enter a string of brackets: ";
    cin >> input;

    isBalanced(input);

    return 0;
}