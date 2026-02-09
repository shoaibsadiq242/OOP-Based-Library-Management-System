# Library Management System (C++ OOP)

A console-based Library Management System implemented in C++ that allows users to manage books with unique IDs, issue and return books, and search or view all books through an interactive menu-driven interface.

---

## Features

* Add new books with **unique Book ID validation**
* View all books in the library
* Search books by Book ID
* Issue books (prevents issuing already issued books)
* Return issued books
* Fully **user-interactive menu**
* Dynamic memory allocation using `new` and `delete`
* Implements Object-Oriented Programming concepts such as classes, objects, and encapsulation

---

## Prerequisites

* C++ compiler (GCC, Clang, or MSVC)
* Terminal or command prompt

---

## How to Run

1. Clone the repository:
   git clone <your-repo-link>
   cd <repository-folder>

2. Compile the program:
   g++ main.cpp -o library

3. Run the program:
   ./library      # Linux / Mac
   library.exe    # Windows

---

## How to Use

1. Run the program.
2. Choose an option from the menu by entering the corresponding number.
3. Follow the prompts to enter book details, issue or return books.
4. The system will display confirmations or search results.
5. After completing an operation, the menu will reappear to perform additional tasks or exit.

---

## Project Structure

* `main.cpp` – contains all program logic

  * `Book` class – manages individual book details
  * `Library` class – manages dynamic array of Book objects
  * `addBook()` – adds a new book with unique ID validation
  * `viewAllBooks()` – displays all books
  * `searchBook()` – searches a book by ID
  * `issueBook()` – issues a book if available
  * `returnBook()` – returns an issued book

---

## License

This project is open source and available for **educational and personal use**.

---

## Author

Implemented by **Malik Shoaib** – Library Management System for beginner to intermediate C++ learners.
