// 1. Assume two existing files: chapter1.txt and chapter2.txt. Populate them with some

// text before running this.

// 2. Open chapter1.txt and chapter2.txt using ifstream in read mode.

// 3. Open book.txt using ofstream in ios::app mode.

// 4. Read from both files and append the contents sequentially to book.txt.

// 5. Ensure a newline is added between chapter contents.

// 6. After writing, open and display book.txt contents to verify concatenation.



#include <iostream>

#include <fstream>

#include <string>

using namespace std;



int main(){

    ofstream truncFile;

    truncFile.open("Book.txt", ios:: trunc);



    if(!truncFile){

        cout << "File Book.txt could not be opened! " <<endl;

        return 1;

    }



    truncFile.close();

    

    ifstream readChp1;

    ifstream readChp2;



    readChp1.open("chapter1.txt", ios::in);

    readChp2.open("chapter2.txt", ios::in);



    ofstream appendFile;

    appendFile.open("Book.txt", ios :: app);



    if(!readChp1) { 

        cout << "File chapter1.txt could not be opened! " <<endl;

        return 1;    

    }



    if(!readChp2) { 

        cout << "File chapter2.txt could not be opened! " <<endl;

        return 1;    

    }



    

    if(!appendFile) { 

        cout << "File Book.txt could not be opened! " <<endl;

        return 1;    

    }





    string line;



    while(getline (readChp1, line)){

    appendFile << line << endl;

    }



    while (getline(readChp2, line)) {

        appendFile << line << endl;

    }



    readChp1.close();

    readChp2.close();

    appendFile.close();





    ifstream readBook;

    readBook.open("Book.txt", ios::in);



    if(!readBook){

        cout << "File Book.txt could not be opened! " <<endl;

        return 1;

    }



    string line3;



    while(getline (readBook, line3)){

    cout << line3 << endl;

    }



    readBook.close();











}
