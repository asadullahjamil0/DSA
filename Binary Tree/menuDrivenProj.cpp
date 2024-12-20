#include <iostream>
#include <limits>  // For numeric_limits
#include <string>  // For string manipulation
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *createNode(int value)
{
    return new Node(value);
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

Node *search(Node *root, int value)
{
    if (root == nullptr || root->data == value)
    {
        return root;
    }
    if (value < root->data)
    {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void displayMenu()
{
    cout << "\nBinary Search Tree Operations\n";
    cout << "1. Insert Node\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Preorder Traversal\n";
    cout << "4. Postorder Traversal\n";
    cout << "5. Search for Node\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

bool isInteger(string input)
{
    for (char c : input)
    {
        if (!isdigit(c) && c != '-')
            return false;
    }
    return true;
}

int main()
{
    Node *root = nullptr;
    int choice;
    string valueInput;
    int value;

    while (true)
    {
        displayMenu();
        cin >> choice;

        // Check if the choice is an integer
        if (cin.fail()) 
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
            cout << "Invalid choice! Please enter a number from the menu." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> valueInput;
            if (isInteger(valueInput)) 
            {
                value = stoi(valueInput);
                root = insert(root, value);
                cout << "Node inserted: " << value << endl;
            }
            else 
            {
                cout << "Invalid input! Please enter an integer value." << endl;
            }
            break;
        case 2:
            cout << "Inorder traversal: ";
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
            } else {
                inorder(root);
            }
            cout << endl;
            break;
        case 3:
            cout << "Preorder traversal: ";
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
            } else {
                preorder(root);
            }
            cout << endl;
            break;
        case 4:
            cout << "Postorder traversal: ";
            if (root == nullptr) {
                cout << "Tree is empty." << endl;
            } else {
                postorder(root);
            }
            cout << endl;
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> valueInput;
            if (isInteger(valueInput))
            {
                value = stoi(valueInput);
                Node *foundNode = search(root, value);
                if (foundNode != nullptr)
                {
                    cout << "Node found with value: " << foundNode->data << endl;
                }
                else
                {
                    cout << "Node not found!" << endl;
                }
            }
            else
            {
                cout << "Invalid input! Please enter an integer value." << endl;
            }
            break;
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
