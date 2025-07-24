#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Preorder Traversal
void preorder(Node* root)
{
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal
void postorder(Node* root)
{
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Count Total Nodes
int countNodes(Node* root)
{
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Height of the Tree
int height(Node* root)
{
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Print All Leaf Nodes
void printLeafNodes(Node* root)
{
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main()
{
    // Creating the Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    cout << "Total Nodes: " << countNodes(root) << "\n";

    cout << "Height of Tree: " << height(root) << "\n";

    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << "\n";

    return 0;
}
