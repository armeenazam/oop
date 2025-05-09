#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    float gpa;
};

int main(){
    Student stud[5];
    

   cout << "Enter data for 5 students:" << endl;
   for (int i = 0; i < 5; ++i) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        cout << "Enter student ID: ";
        cin >> stud[i].id;
        cin.ignore();  
        cout << "Enter student name: ";
        getline(cin, stud[i].name); 
        cout << "Enter GPA: ";
        cin >> stud[i].gpa;
    }

    ofstream file;
    file.open("students.txt", ios::out);
    if(!file){
        cout << "File could not be opened! " <<endl;
        return 1;
    }

    for (int i = 0; i < 5; ++i) {
        file << "ID: " << stud[i].id << ", Name: " << stud[i].name << ", GPA: " << stud[i].gpa << endl;
    }

    file.close();
    cout << "/nData has been written to the file!" << endl;

    Student newStd;
    cout << "\nEnter data for 1 additional student to append to the file:" << endl;
    cout << "Enter Student ID: ";
    cin >> newStd.id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, newStd.name);
    cout << "Enter GPA: ";
    cin >> newStd.gpa;

    ofstream appendFile("students.txt", ios::app);
    if(!appendFile){
        cerr << "Error opening the file for appending!" << endl;
        return 1;
    }

    appendFile << "ID: " << newStd.id << ", Name: " << newStd.name << ", GPA: " << newStd.gpa;
    appendFile.close();

    cout << "\nDisplaying all students records from the file: " << endl;
    ifstream readFile ("students.txt", ios::in);
    if(!readFile){
        cerr << "Error opening the file for appending!" << endl;
        return 1;
    }

    string line;
    while(getline (readFile,line)){
        cout << line << endl;
    }

    readFile.close();
    return 0;
}

