#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Class for Linked List operations
class LinkedList {
public:
    Node* head;
    
    LinkedList() {
        head = nullptr;
    }
    
    // Function to insert a node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    
    cout << "Linked List: ";
    list.display();
    
    list.deleteNode(20);
    cout << "After deleting 20: ";
    list.display();
    
    return 0;
}
