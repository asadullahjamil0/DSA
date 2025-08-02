#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Utility to get height of node
int height(Node* n) {
    return n ? n->height : 0;
}

// Utility to get balance factor
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Update height
void updateHeight(Node* n) {
    n->height = 1 + max(height(n->left), height(n->right));
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert with balancing
Node* insert(Node* node, int key) {
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    updateHeight(node);
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// In-order traversal
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int keys[] = { 10, 20, 30, 40, 50, 25 };
    for (int key : keys)
        root = insert(root, key);

    cout << "In-order traversal of AVL tree:\n";
    inOrder(root);
    cout << endl;

    return 0;
}
