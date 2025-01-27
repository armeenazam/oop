#include <iostream>
#include <string>
using namespace std;
typedef struct Event {
    string eventName;
    string date;
    string venue;
    string organizer;
} Event;
int main() {
    int numEvents;
    cout << "Enter the total number of events: ";
    cin >> numEvents;
    cin.ignore();
    Event* events = new Event[numEvents];
    for (int i = 0; i < numEvents; ++i) {
        cout << "\nEnter details for Event no. " << i + 1 << endl;
        cout << "Enter Event Name: ";
        getline(cin, events[i].eventName);
        cout << "Enter Event Date (DD/MM/YYYY) (Note: No spaces are allowed): ";
        cin >> events[i].date;
        cin.ignore();
        cout << "Enter Event Venue: ";
        getline(cin, events[i].venue);
        cout << "Enter Event Organizer: ";
        getline(cin, events[i].organizer);
    }
    cout << "\nAll events:\n";
    for (int i = 0; i < numEvents; ++i) {
        cout << "\nEvent no. " << i + 1 << ":" << endl;
        cout << "Event Name: " << events[i].eventName << endl;
        cout << "Event Date: " << events[i].date << endl;
        cout << "Event Venue: " << events[i].venue << endl;
        cout << "Event Organizer: " << events[i].organizer << endl;
    }
    string searchDate;
    char choice;
    do {
        cout << "\nEnter a date to search for events (DD/MM/YYYY): ";
        cin >> searchDate;
        bool found = false;
        cout << "\nEvents on " << searchDate << ":\n";
        for (int i = 0; i < numEvents; ++i) {
            if (events[i].date == searchDate) {
                cout << "\nEvent no. " << i + 1 << ":" << endl;
                cout << "Event Name: " << events[i].eventName << endl;
                cout << "Event Date: " << events[i].date << endl;
                cout << "Event Venue: " << events[i].venue << endl;
                cout << "Event Organizer: " << events[i].organizer << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No events found for the given date." << endl;
        }
        cout << "\nDo you want to search for another date? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    delete[] events; 
    return 0;
}
