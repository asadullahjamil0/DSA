#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value); // If the tree is empty, create a new node
    }

    // If value is smaller than root, insert into left subtree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    // If value is greater than root, insert into right subtree
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST
bool search(Node *root, int value)
{
    // Base case: root is null or value is present at the root
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == value)
    {
        return true;
    }

    // If value is smaller, search in the left subtree
    if (value < root->data)
    {
        return search(root->left, value);
    }

    // If value is greater, search in the right subtree
    return search(root->right, value);
}

// Function for inorder traversal (left, root, right)
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);       // Traverse left subtree
        cout << root->data << " "; // Visit root
        inorder(root->right);      // Traverse right subtree
    }
}

int main()
{
    Node *root = nullptr; // Start with an empty tree

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Inorder traversal (prints the elements in sorted order)
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // Search for a value in the BST
    int searchValue = 40;
    if (search(root, searchValue))
    {
        cout << "Value " << searchValue << " found in the BST." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the BST." << endl;
    }

    return 0;
}
