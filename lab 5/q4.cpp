#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Parameterized Constructor
    BankAccount(int accNum, string name, double bal) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        cout << "Depositing " << amount << " into account " << accountNumber << "...\n";
        balance += amount;
        cout << "New Balance: " << balance << endl << endl;
    }

    void withdraw(double amount) {
        if (balance < amount) {
            cout << "Insufficient balance in account " << accountNumber << "!\n\n";
            return;
        }
        cout << "Withdrawing " << amount << " from account " << accountNumber << "...\n";
        balance -= amount;
        cout << "Remaining Balance: " << balance << endl << endl;
    }

    void display() {
        cout << "--------------------------------------\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "--------------------------------------\n\n";
    }
};

int main() {
    BankAccount accounts[3] = {
        BankAccount(1000, "Armeen Azam", 100000),
        BankAccount(1001, "Ariza Iqbal", 200000),
        BankAccount(1002, "Manahil Abbas", 300000)
    };
    for (int i = 0; i < 3; i++) {
        cout << "\nInitial Details of Account " << i + 1 << ":\n";
        accounts[i].display();

        accounts[i].deposit(500.0);

        accounts[i].withdraw(200.0);

        cout << "Updated Details of Account " << i + 1 << ":\n";
        accounts[i].display();
    }

    return 0;
}
