#ifndef BOOK
#define BOOK

#include<string>
using namespace std;

class Book{
private:    
    string title;
    string author;
    string ISBN;
public:
    Book(string t, string a, string isbn);

    string getTitle();
    string getAuthor();
    string getISBN();   
};
#endif