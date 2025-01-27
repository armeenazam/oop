#include <iostream>
using namespace std;
typedef struct Register {
    string courseId;
    string courseName;
} Register;
typedef struct Student {
    string studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
    Register registration;
} Student;
int main() {
    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;
    cin.ignore();
    Student* students = new Student[numberOfStudents];
    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Course ID: ";
        cin >> students[i].registration.courseId;
        cin.ignore();
        cout << "Course Name: ";
        getline(cin, students[i].registration.courseName);
        cout << "Student ID: ";
        cin >> students[i].studentId;
        cout << "First Name: ";
        cin >> students[i].firstName;
        cout << "Last Name: ";
        cin >> students[i].lastName;
        cout << "Cell Number: ";
        cin >> students[i].cellNo;
        cout << "Email: ";
        cin >> students[i].email;
        cout << endl;}
    cout << "\nDisplaying information of all students:\n";
    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "Student " << i + 1 << " Details:\n";
        cout << "Course ID: " << students[i].registration.courseId << endl;
        cout << "Course Name: " << students[i].registration.courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Cell Number: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;}
    delete[] students;}
  

