#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Default constructor
    Account() {
        this->accountNumber = "N/A";
        this->accountHolderName = "N/A";
        this->balance = 0.0;
    }

    // Parameterized constructor
    Account(string accountNumber, string accountHolderName, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    // Deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw money from the account
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) { // FIXED: Allow withdrawing the full balance
            balance -= amount;
            cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
            return true;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
            return false;
        }
    }

    // Check balance
    void checkBalance() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    string accNum, accHolder;
    double initialBalance;
    
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, accHolder);
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;
    
    Account userAccount(accNum, accHolder, initialBalance);
    
    int choice;
    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                double depositAmount;
                cout << "Enter amount to deposit: ";
                cin >> depositAmount;
                userAccount.deposit(depositAmount);
                break;
            case 2:
                double withdrawAmount;
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                userAccount.withdraw(withdrawAmount);
                break;
            case 3:
                userAccount.checkBalance();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
