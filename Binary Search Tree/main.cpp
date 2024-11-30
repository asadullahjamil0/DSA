#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (root->data > val)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *searchBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

int main()
{
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    inorder(root);

    // Seearch Binary tree
    searchBST(root, 5);
    if (searchBST == NULL)
    {
        cout << endl
             << "Key does not exist";
    }
    else
    {
        cout << endl
             << "Key exists";
    }

    return 0;
}