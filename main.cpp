#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

vector<Book> library;

void addBook() {
    Book b;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, b.title);
    cout << "Enter Book Author: ";
    getline(cin, b.author);
    library.push_back(b);
    cout << "Book added successfully!\n";
}

void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    for (Book b : library) {
        if (b.id == id) {
            cout << "Book Found: " << b.title << " by " << b.author << endl;
            return;
        }
    }
    cout << "Book not found.\n";
}

void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    for (size_t i = 0; i < library.size(); i++) {
        if (library[i].id == id) {
            library.erase(library.begin() + i);
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void menu() {
    int choice;
    do {
        cout << "\nLibrary Menu:\n1. Add Book\n2. Search Book\n3. Delete Book\n4. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: deleteBook(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while(choice != 4);
}

int main() {
    menu();
    return 0;
}
