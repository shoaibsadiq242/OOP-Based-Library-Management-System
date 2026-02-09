#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    Book() {
        bookID = 0;
        title = "";
        author = "";
        isIssued = false;
    }

    void inputBook(int id) {
        bookID = id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        isIssued = false;
    }

    int getBookID() {
        return bookID;
    }

    bool getIssueStatus() {
        return isIssued;
    }

    void issueBook() {
        isIssued = true;
    }

    void returnBook() {
        isIssued = false;
    }

    void displayBook() {
        cout << "\n-----------------------------\n";
        cout << "Book ID   : " << bookID << endl;
        cout << "Title     : " << title << endl;
        cout << "Author    : " << author << endl;
        cout << "Status    : " << (isIssued ? "Issued" : "Available") << endl;
        cout << "-----------------------------\n";
    }
};

class Library {
private:
    Book* books;
    int capacity;
    int count;

public:
    Library(int cap) {
        capacity = cap;
        count = 0;
        books = new Book[capacity];
    }

    ~Library() {
        delete[] books;
    }

    void addBook() {
        if (count >= capacity) {
            cout << "\nLibrary is full. Cannot add more books.\n";
            return;
        }

        int newID;
        cout << "\n--- Add New Book ---";
        cout << "\nEnter Book ID: ";
        cin >> newID;

        // Check for duplicate ID
        for (int i = 0; i < count; i++) {
            if (books[i].getBookID() == newID) {
                cout << "\nThis Book ID is already taken. Try another ID.\n";
                return;
            }
        }

        books[count].inputBook(newID);
        count++;

        cout << "\nBook added successfully!\n";
    }

    void viewAllBooks() {
        if (count == 0) {
            cout << "\nNo books available in library.\n";
            return;
        }

        cout << "\n--- All Books in Library ---\n";
        for (int i = 0; i < count; i++) {
            books[i].displayBook();
        }
    }

    void searchBook() {
        if (count == 0) {
            cout << "\nLibrary is empty.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to search: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getBookID() == id) {
                cout << "\nBook found!\n";
                books[i].displayBook();
                return;
            }
        }

        cout << "\nBook not found.\n";
    }

    void issueBook() {
        if (count == 0) {
            cout << "\nLibrary is empty.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getBookID() == id) {
                if (books[i].getIssueStatus()) {
                    cout << "\nThis book is already issued.\n";
                }
                else {
                    books[i].issueBook();
                    cout << "\nBook issued successfully.\n";
                }
                return;
            }
        }

        cout << "\nBook not found.\n";
    }

    void returnBook() {
        if (count == 0) {
            cout << "\nLibrary is empty.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getBookID() == id) {
                if (!books[i].getIssueStatus()) {
                    cout << "\nThis book was not issued.\n";
                }
                else {
                    books[i].returnBook();
                    cout << "\nBook returned successfully.\n";
                }
                return;
            }
        }

        cout << "\nBook not found.\n";
    }
};

int main() {
    int size;
    cout << "===== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "Enter maximum number of books for library: ";
    cin >> size;

    Library library(size);
    int choice;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            library.addBook();
            break;
        case 2:
            library.viewAllBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.issueBook();
            break;
        case 5:
            library.returnBook();
            break;
        case 0:
            cout << "\nExiting program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
