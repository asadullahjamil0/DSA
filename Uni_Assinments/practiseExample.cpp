#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    int bookID;
    string bookTitle;
    string author;
    int quantity;
    Book *next;

    Book(int bookID, string bookTitle, string author, int quantity) : bookID(bookID), bookTitle(bookTitle), author(author), quantity(quantity), next(nullptr) {}
};

class Library
{
public:
    Book *head;

    Library() : head(nullptr) {}

    // Add a new book to the inventory
    void addBook(int bookID, string bookTitle, string author, int quantity)
    {
        Book *newBook = new Book(bookID, bookTitle, author, quantity);
        newBook->next = nullptr;
        if (head == nullptr)
        {
            head = newBook;
        }
        else
        {
            Book *ptr = head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = newBook;
        }
    }

    // Delete a book from the inventory
    void deleteBook(int bookID)
    {
        Book *current = head;
        Book *prev = nullptr;

        while (current != nullptr && current->bookID != bookID)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Book with ID " << bookID << " not found.\n";
            return;
        }

        if (prev == nullptr)
        {
            head = current->next; // If the book is the first one in the list
        }
        else
        {
            prev->next = current->next; // Bypass the book to delete
        }

        delete current;
        cout << "Book with ID " << bookID << " deleted.\n";
    }

    // Update the quantity of a book
    void updateQuantity(int bookID, int newQuantity)
    {
        Book *current = head;
        while (current != nullptr)
        {
            if (current->bookID == bookID)
            {
                current->quantity = newQuantity;
                cout << "Quantity of book ID " << bookID << " updated to " << newQuantity << ".\n";
                return;
            }
            current = current->next;
        }
        cout << "Book with ID " << bookID << " not found.\n";
    }

    // Find a book by its ID
    void findBook(int bookID)
    {
        Book *current = head;
        while (current != nullptr)
        {
            if (current->bookID == bookID)
            {
                cout << "Found Book: ID " << current->bookID;
                cout << ", Title: " << current->bookTitle;
                cout << ", Author: " << current->author;
                cout << ", Quantity: " << current->quantity << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Book with ID " << bookID << " not found.\n";
    }

    // Print the entire inventory of books
    void printLibrary()
    {
        cout << "Book ID    Title                Author              Quantity\n";
        cout << "-----------------------------------------------------------\n";
        Book *current = head;
        while (current != nullptr)
        {
            cout << current->bookID << "         " << current->bookTitle;
            cout << "        " << current->author;
            cout << "        " << current->quantity << endl;
            current = current->next;
        }
        cout << endl; // For better spacing after the list
    }
};

int main()
{
    cout << "---------------------------------------------\n";
    cout << "Library Book Management System [BC240216012]\n"; // Just change your ID in brackets.
    cout << "---------------------------------------------\n";

    Library library;

    // Pre-populated data for demonstration
    library.addBook(201, "The Great Gatsby", "F. Scott Fitzgerald", 12);
    library.addBook(202, "1984", "George Orwell", 8);
    library.addBook(203, "To Kill a Mockingbird", "Harper Lee", 15);

    cout << "\nLibrary Inventory Added.\n";
    library.printLibrary(); // Print initial inventory

    cout << "Finding Book ID 201:\n";
    library.findBook(201); // Test finding book with ID 201
    cout << endl;

    cout << "After deleting '1984' and Updating 'To Kill a Mockingbird' Quantity...\n\n";

    library.deleteBook(202);         // Delete book with ID 202
    library.updateQuantity(203, 20); // Update quantity for 'To Kill a Mockingbird'

    library.printLibrary(); // Print updated inventory

    return 0;
}
