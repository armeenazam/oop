#include "Library.h"
#include <iostream>
using namespace std;

int main() {
    Book* b1 = new Book("1984", "George Orwell", "12345");
    Book* b2 = new Book("Brave New World", "Aldous Huxley", "67890");
    
    Book* books[] = {b1, b2};
  
    Library lib(2, books);

    if (lib.searchBook("1984", "George Orwell", "12345")) {
        cout << "Book found!" << endl;
    } else {
        cout << "Book not found!" << endl;
    }
    
    lib.addBook("To Kill a Mockingbird", "Harper Lee", "54321");
   
    lib.removeBook("1984", "George Orwell", "12345");
 
    delete b1;
    delete b2;

    return 0;
}
