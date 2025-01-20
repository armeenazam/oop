#include <iostream>
using namespace std;

int main() {
    int students;
    cout << "Enter the number of students: ";
    cin >> students;
    int data[students][3]; 
    for (int i = 0; i < students; i++) {
        cout << "Enter the marks of English for student " << i + 1 << ": ";
        cin >> data[i][0];
        cout << "Enter the marks of Maths for student " << i + 1 << ": ";
        cin >> data[i][1];
        cout << "Enter the marks of Science for student " << i + 1 << ": ";
        cin >> data[i][2];
    }
    for (int i = 0; i < students; i++) {
      
        float total = data[i][0] + data[i][1] + data[i][2];
        float avg = total / 3.0;
        cout << "\nResults for student " << i + 1 << ":\n";
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << avg << endl;
        if (avg >= 90) {
            cout << "Grade: A\n";
        } 
		else if (avg >= 80 && avg <= 89) {
            cout << "Grade: B\n";
        } 
		else if (avg >= 70 && avg <=79) {
            cout << "Grade: C\n";
        }
        else if (avg >= 60 && avg <=69) {
            cout << "Grade: D\n";
        } else {
            cout << "Grade: F\n";
        }
    }

    return 0;
}
