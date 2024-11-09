#include <iostream>
#include <string>
using namespace std;

class Part
{
public:
    int partID;
    string partName;
    int quantity;
    Part *next;

    Part(int partID, string partName, int quantity) : partID(partID), partName(partName), quantity(quantity), next(nullptr) {}
};

class Inventory
{
public:
    Part *head;

    Inventory() : head(nullptr) {}

    // TODO: Implement the addPart function
    void addPart(int partID, string partName, int quantity)
    {
        Part *newPart = new Part(partID, partName, quantity);
        newPart->next = NULL;
        if (head == NULL)
        {
            head = newPart;
        }
        else
        {
            Part *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newPart;
        }
    }

    // TODO: Implement the deletePart function
    void deletePart(int partID)
    {
        Part *current = head;
        Part *prev = NULL;

        while (current != NULL && current->partID != partID)
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
        {
            return;
        }
        if (prev == NULL)
        {
            head = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        delete current;
    }

    // TODO: Implement the updateQuantity function
    void updateQuantity(int partID, int newQuantity)
    {
        Part *current = head;
        while (current != NULL)
        {
            if (current->partID == partID)
            {
                current->quantity = newQuantity;
                return;
            }
            current = current->next;
        }
    }

    // TODO: Implement the findPart function
    void findPart(int partID)
    {
        Part *current = head;
        while (current != NULL)
        {
            if (current->partID == partID)
            {
                cout << "Found Part: ID " << current->partID;
                cout << ", Name" << current->partName;
                cout << ", Quantity " << current->quantity << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Part with ID " << partID << " not found.\n";
    }

    void printInventory()
    {
        cout << "Part ID    Part Name         Quantity" << endl;
        cout << "-------------------------------------" << endl;
        Part *current = head;
        while (current != nullptr)
        {
            cout << current->partID << "         " << current->partName;
            cout << "                " << current->quantity << endl;
            current = current->next;
        }
        cout << endl; // For better spacing after the list
    }
};

int main()
{
    cout << "----------------------------------------------" << endl;
    cout << "Computer Parts Management System [BC240216012]" << endl; // Just Change your ID here in brackets.
    cout << "----------------------------------------------" << endl;

    Inventory storeInventory;

    // Pre-populated data for demonstration
    storeInventory.addPart(101, "SSD", 25);
    storeInventory.addPart(102, "RAM", 40);
    storeInventory.addPart(103, "HDD", 15);

    cout << endl
         << "Inventory Added." << endl;
    storeInventory.printInventory(); // Print initial inventory

    cout << "Finding Part ID 101:" << endl;
    storeInventory.findPart(101); // Test finding part with ID 101
    cout << endl;

    cout << "After deleting SSD and Updating RAM Quantity..." << endl
         << endl;

    storeInventory.deletePart(101);         // Delete part with ID 101
    storeInventory.updateQuantity(102, 50); // Update quantity for RAM

    storeInventory.printInventory(); // Print updated inventory

    return 0;
}
