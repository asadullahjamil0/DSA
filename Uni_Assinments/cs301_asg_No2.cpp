#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    int label;
    BinarySearchTree* left;
    BinarySearchTree* right;

public:
    BinarySearchTree() : label(0), left(nullptr), right(nullptr) {}
    BinarySearchTree(int label) : label(label), left(nullptr), right(nullptr) {}

    void setLabel(int label) { this->label = label; }
    void setLeft(BinarySearchTree* left) { this->left = left; }
    void setRight(BinarySearchTree* right) { this->right = right; }

    int getLabel() { return label; }
    BinarySearchTree* getLeft() { return left; }
    BinarySearchTree* getRight() { return right; }

    bool isLeaf() { return left == nullptr && right == nullptr; }

    void insert(BinarySearchTree*& root, int label) {
        if (label == 0) {
            cout << "Zero values cannot be inserted into the tree." << endl;
            return;
        }

        if (!root) {
            root = new BinarySearchTree(label);
            cout << label << " inserted successfully." << endl;
        } else if (label < root->label) {
            insert(root->left, label);
        } else if (label > root->label) {
            insert(root->right, label);
        } else {
            cout << label << " is a duplicate in this Binary Search Tree (BST). Cannot be inserted." << endl;
        }
    }

    void display(BinarySearchTree* root) {
        if (root) {
            display(root->left);
            cout << root->label << " ";
            display(root->right);
        }
    }
};

int main() {
    BinarySearchTree* root = nullptr;
    int numId = 2412;
    cout << "Your Student ID First two and last two digits are: " << numId << endl;

    int digits[] = {2, 4, 1, 2};
    for (int digit : digits) {
        root->insert(root, digit);
    }

    cout << "Displaying the Tree Nodes in in-order sequence: ";
    root->display(root);
    cout << endl;

    return 0;
}