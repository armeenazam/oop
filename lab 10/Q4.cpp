// Q4. You are testing how file pointers work in a file while reading and writing.

// Requirements:

// 1. Write the sentence "C++ is a powerful programming language." to a file named

// info.txt using ofstream in ios::out mode.

// 2. Reopen the file using fstream with both ios::in | ios::out modes.

// 3. Display the initial position of get pointer using tellg() and put pointer using tellp().

// 4. Use seekg(6) to move the read pointer to the word "powerful" and read the word

// from there.

// 5. Use seekp(6) to move the write pointer to the same position, and overwrite

// "powerful" with "dynamic" (same length).

// 6. Use tellg() and tellp() again to show the new pointer positions.

// 7. Display the updated content of the file.



#include <iostream>

#include <fstream>

#include <string>

using namespace std;



int main(){

    ofstream File("info.txt", ios::out);

    if(!File){

        cout << "Failed to open file!" <<endl;

        return 1;

    }



    File << "C++ is a powerful programming language.";



    File.close();



    fstream File_open("info.txt", ios::in | ios::out);

    if (!File_open) {

        cout << "Failed to open file!" << endl;

        return 1;

    }



    cout << "Initial position of get pointer: " << File_open.tellg() << endl;

    cout << "Initial position of put pointer: " << File_open.tellp() << endl;



    File_open.seekg(9);

    char word[9];

    File_open.read(word, 8);

    word[8] = '\0';

    cout << "Word at position 9: " << word << endl;



    File_open.seekp(9);

    File_open.write("dynamic", 8);



    cout << "Current position of get pointer: " << File_open.tellg() << endl;

    cout << "Current position of put pointer: " << File_open.tellp() << endl;



    File_open.seekg(0);

    string updatedLine;

    getline(File_open, updatedLine);

    cout << "Updated line: " << updatedLine << endl;

    



    return 0;

}
