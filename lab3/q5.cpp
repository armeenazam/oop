#include <iostream>
using namespace std;

class Calendar {
private:
    string jan[31];
    string feb[29];
    string march[31];  
    string april[30];
    string may[31];
    string june[30];
    string july[31];
    string aug[31];
    string sep[30];
    string oct[31];
    string nov[30];
    string dec[31];
    int year;

    string* getMonthArray(string month, int& daysInMonth) {
        if (month == "January") {
            daysInMonth = 31;
            return jan;
        } else if (month == "February") {
            daysInMonth = 29;
            return feb;
        } else if (month == "March") {
            daysInMonth = 31;
            return march;
        } else if (month == "April") {
            daysInMonth = 30;
            return april;
        } else if (month == "May") {
            daysInMonth = 31;
            return may;
        } else if (month == "June") {
            daysInMonth = 30;
            return june;
        } else if (month == "July") {
            daysInMonth = 31;
            return july;
        } else if (month == "August") {
            daysInMonth = 31;
            return aug;
        } else if (month == "September") {
            daysInMonth = 30;
            return sep;
        } else if (month == "October") {
            daysInMonth = 31;
            return oct;
        } else if (month == "November") {
            daysInMonth = 30;
            return nov;
        } else if (month == "December") {
            daysInMonth = 31;
            return dec;
        } else {
            daysInMonth = 0;
            return nullptr;
        }
    }

public:
    Calendar(int y) {
        year = y;
    }

    void addTask(string task, int date, string month) {
        int daysInMonth;
        string* monthArray = getMonthArray(month, daysInMonth);

        if (!monthArray || date < 1 || date > daysInMonth) {
            cout << "Invalid date or month!" << endl;
            return;
        }

        monthArray[date - 1] = task;
        cout << "Task added on " << month << " " << date << ": " << task << endl;
    }

    void removeTask(int date, string month) {
        int daysInMonth;
        string* monthArray = getMonthArray(month, daysInMonth);

        if (!monthArray || date < 1 || date > daysInMonth) {
            cout << "Invalid date or month!" << endl;
            return;
        }

        monthArray[date - 1] = "";
        cout << "Task removed from " << month << " " << date << endl;
    }

    void showTasks() {
        cout << "\n=== Task List for Year " << year << " ===\n";

        string months[] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

        for (int i = 0; i < 12; i++) {
            int daysInMonth;
            string* monthArray = getMonthArray(months[i], daysInMonth);

            for (int d = 0; d < daysInMonth; d++) {
                if (!monthArray[d].empty()) {
                    cout << months[i] << " " << d + 1 << ": " << monthArray[d] << endl;
                }
            }
        }
    }
};

int main() {
    Calendar myCalendar(2025);

    myCalendar.addTask("Doctor appointment", 5, "January");
    myCalendar.addTask("Project deadline", 12, "March");
    myCalendar.addTask("Friend's birthday", 20, "July");
    myCalendar.addTask("Meeting with boss", 28, "September");
    myCalendar.addTask("Vacation starts", 15, "December");

    myCalendar.showTasks();

    myCalendar.removeTask(12, "March");

    cout << "\nUpdated task list:\n";
    myCalendar.showTasks();

    return 0;
}
