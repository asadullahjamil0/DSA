#include <iostream>
using namespace std;

// Node structure for AVL tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Utility function to get the height of a node
int height(Node* n) {
    return n ? n->height : 0;
}

// Get balance factor of node n
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// Insert a key into the AVL tree
Node* insert(Node* root, int key) {
    // Perform normal BST insertion
    if (!root)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys not allowed

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Check balance
    int balance = getBalance(root);

    // Perform rotations

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // No rotation needed
}

// In-order traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main function
int main() {
    Node* root = nullptr;

    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int key : keys) {
        root = insert(root, key);
    }

    cout << "Inorder traversal of AVL tree:\n";
    inorder(root);
    cout << endl;

    return 0;
}
