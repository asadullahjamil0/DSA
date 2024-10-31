#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertHead(Node *&head, int val)
{
    Node *new_Node = new Node(val);
    new_Node->next = head;
    head = new_Node;
}

void insertAtTail(Node *&head, int val)
{
    Node *new_Node = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_Node;
}

void insertAtPosition(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertHead(head, val);
        return;
    }
    Node *new_Node = new Node(val);
    Node *temp = head;
    int current_pos = 0;
    while (current_pos != pos - 1)
    {
        temp = temp->next;
        current_pos++;
    }
    new_Node->next = temp->next;
    temp->next = new_Node;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    insertHead(head, 2);
    display(head);
    insertHead(head, 1);
    display(head);
    insertAtTail(head, 3);
    display(head);
    insertAtPosition(head, 4, 3);
    display(head);

    return 0;
}