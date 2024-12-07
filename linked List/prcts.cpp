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

void insertHeadt(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtLast(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtPosition(Node *&head, int val, int pos)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    int curr_pos = 0;
    if (pos == 0)
    {
        insertAtLast(head, val);
        return;
    }
    while (curr_pos != pos - 1)
    {
        temp = temp->next;
        curr_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtKth(Node *&head, int kth, int val)
{
    Node *temp = head;
    int curr_pos = 0;
    while (curr_pos != kth)
    {
        temp = temp->next;
        curr_pos++;
    }
    temp->val = val;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(Node *&head)
{
    Node *second_last = head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }

    Node *temp = second_last->next;
    second_last->next = NULL;
    free(temp);
}

void displayNode(Node *head)
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
    insertHeadt(head, 2);
    displayNode(head);
    insertHeadt(head, 1);
    displayNode(head);
    insertAtLast(head, 3);
    displayNode(head);
    insertAtPosition(head, 4, 1);
    displayNode(head);
    updateAtKth(head, 2, 5);
    displayNode(head);
    // Deleting a head node of linked list
    deleteAtHead(head);
    displayNode(head);
    // deleting an element from the end of the list
    deleteAtEnd(head);
    displayNode(head);

    return 0;
}