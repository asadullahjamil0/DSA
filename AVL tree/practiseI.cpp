#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Get height of the node
int height(Node* node) {
    return node ? node->height : 0;
}

// Get balance factor of node
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Update the height of the node
int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert function
Node* insert(Node* node, int key) {
    if (!node)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Balance the node
    // Left Left
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // return unchanged node
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main to test AVL Tree
int main() {
    Node* root = nullptr;

    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int key : keys) {
        root = insert(root, key);
    }

    cout << "Inorder traversal of the constructed AVL tree:\n";
    inorder(root);
    cout << endl;

    return 0;
}
