#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node *left, *right;
    int height;
};

// Function to get the height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Function to get balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Create a new node
Node* createNode(int key) {
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
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// Insert a node into AVL tree
Node* insert(Node* node, int key) {
    if (!node) return createNode(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed
    
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);
    
    // Perform rotations if unbalanced
    if (balance > 1 && key < node->left->key) // Left Left Case
        return rightRotate(node);
    if (balance < -1 && key > node->right->key) // Right Right Case
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) { // Left Right Case
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) { // Right Left Case
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// In-order traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    
    cout << "In-order traversal of AVL Tree: ";
    inorder(root);
    cout << endl;
    
    return 0;
}