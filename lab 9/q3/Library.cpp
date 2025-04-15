#include "Library.h"
#include <iostream>
#include <string>
using namespace std;


Library::Library(int n, Book* books[]) {
    numBooks = n;
    book = new Book*[n]; 
    
    for (int i = 0; i < n; ++i) {
        book[i] = new Book(*books[i]); 
    }
}

Library::~Library() {
    for (int i = 0; i < numBooks; ++i) {
        delete book[i];
    }
    delete[] book;  
}

void Library::addBook(string title, string author, string ISBN) {
    Book** newBooks = new Book*[numBooks + 1];

    for (int i = 0; i < numBooks; ++i) {
        newBooks[i] = book[i];
    }
    
    newBooks[numBooks] = new Book(title, author, ISBN);
    delete[] book;
    book = newBooks;
    numBooks++; 
}

void Library::removeBook(string title, string author, string ISBN) {
    int index = -1;
    
    for (int i = 0; i < numBooks; ++i) {
        if (book[i]->getTitle() == title &&
            book[i]->getAuthor() == author &&
            book[i]->getISBN() == ISBN) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Book not found.\n";
        return;
    }

    delete book[index];

    for (int i = index; i < numBooks - 1; ++i) {
        book[i] = book[i + 1];
    }

    numBooks--;
}

bool Library::searchBook(string title, string author, string ISBN) {
    for (int i = 0; i < numBooks; ++i) {
        if (book[i]->getTitle() == title &&
            book[i]->getAuthor() == author &&
            book[i]->getISBN() == ISBN) {
            return true;  
    }
    return false;  
}
