#ifndef LIBRARY
#define LIBRARY

#include "Book.h"
#include<string>
using namespace std;

class Library{
private:
   int numBooks;
   Book **book;   
public:
   Library(int n, Book *books[]) ;
   ~Library();

   void addBook(string title, string author, string ISBN); 

   void removeBook(string title, string author, string ISBN);    
   
   bool searchBook(string title, string author, string ISBN); 
};

#endif
