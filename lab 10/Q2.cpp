Q2
// 1. Prompt the user to enter:

// ○ string name

// ○ string email

// ○ int yearsOfExperience

// ○ string summary

// 2. Write this data to a file called resume.txt.

// 3. Use ofstream with ios::trunc to ensure that any previous contents are completely

// deleted before writing new data.

// 4. After writing, read back and display the contents to confirm that the file only has the

// latest entry.



#include <iostream>

#include <fstream>

#include <string>

using namespace std;



struct Resume{

    string name;

    string email;

    int yearsOfExperience;

    string summary;

};





int main(){

    Resume r1;

    cout << "Enter data for your resume: " << endl;



    cout << "Name: ";

    getline(cin,r1.name);

    cout << "Email: ";

    getline(cin,r1.email);

    cout <<"Experience: ";

    cin >> r1.yearsOfExperience;

    cin.ignore();

    cout << "Summary: ";

    getline(cin,r1.summary);



    ofstream file;

    file.open("Resume.txt", ios::out);

    if(!file){

        cout << "File could not be opened! " <<endl;

        return 1;

    }



    file << "Name: " << r1.name << ", Email: " << r1.email << ", Experience: " << r1.yearsOfExperience << ", Summary: " << r1.summary;



    file.close();

    cout << "\nData has been written to the file!" << endl;



    ofstream truncFile;

    truncFile.open("Resume.txt", ios::out | ios::trunc);

    if(!truncFile){

        cout << "File could not be opened! " << endl;

        return 1;

    }



    truncFile << "\nThe file content was truncated." << endl;

    truncFile.close();



    ifstream readFile;

    readFile.open("Resume.txt", ios:: in);

    if(!readFile){

        cout << "File could not be opened! " << endl;

        return 1;

    }



    string line;

    while(getline(readFile, line)){

        cout << line << endl;

    }



    readFile.close();



    return 0;

}
