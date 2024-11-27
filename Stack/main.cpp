#include <iostream>
using namespace std;
#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Cannot insert new element!" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    Stack st;
    st.pop();
    st.push(34);
    st.push(52);
    st.push(91);
    st.push(69);
    st.push(79);
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.Top() << endl;
    st.push(134);
    cout << st.empty() << endl;

    return 0;
}