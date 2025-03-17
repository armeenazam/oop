// #include<iostream>
// #include<string>
// using namespace std;

// class Account{
// protected:
//     int accountNumber;
//     double balance;
//     string accountHolderName;
//     //string accountType;  
// public:
//     Account(int accNum, double b, string name){
//         accountNumber = accNum;
//         balance = b;
//         accountHolderName = name;
//     } 

//     void depositAmount(double amount){
//         balance += amount;
//         cout << "Rs " << amount << "deposited." << endl;
//         cout << "New balance: " << balance << endl;
//     }     

//     void withdrawAmount(double amount){
//         if(amount <= balance){
//             balance -= amount;
//             cout << "Rs " << amount << "withdrew." << endl;
//             cout << "New balance: " << balance << endl;
//         }
//         else{
//             cout << "Insufficient balance."<< endl;
//         }
//     }

//     double calculateInterest(int years){
//         const double rate = 0.05;
//         double interest;
//         interest = balance * rate * years;
//         return interest;
//     }

//     void printStatement(){
        
//     }
    
//     void getAccountInfo(){
//         cout << "Account Number: " << accountNumber << endl
//         << "Account Holder Name: " << accountHolderName <<endl
//         << "Balance: " << balance << endl;
//     }
// };

// class SavingsAccount : public Account{};
// class CheckingAccount : public Account{};
// class FixedDepositAccount : public Account{};

#include <iostream>
#include <string>

using namespace std;

// Base class for all accounts
class Account {
protected:
    int accnum;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNum, string holderName, double initialBalance, string type = "General")
        : accnum(accNum), accountHolderName(holderName), balance(initialBalance), accountType(type) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " into account. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds or invalid withdrawal amount!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation is not available for this account type." << endl;
    }

    virtual void printStatement() {
        cout << "Account Statement for " << accountHolderName << " (" << accountType << "):" << endl;
        cout << "Account Number: " << accnum << endl;
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo() {
        cout << "Account Info:" << endl;
        cout << "Account Number: " << accnum << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, string holderName, double initialBalance, double rate)
        : Account(accNum, holderName, initialBalance, "Savings"), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest of " << interest << " added. New balance: " << balance << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class for CheckingAccount
class CheckingAccount : public Account {
private:
    double minimumBalance;

public:
    CheckingAccount(int accNum, string holderName, double initialBalance, double minBalance)
        : Account(accNum, holderName, initialBalance, "Checking"), minimumBalance(minBalance) {}

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance && amount > 0) {
            balance -= amount;
            cout << "Withdrew " << amount << " from checking account. New balance: " << balance << endl;
        } else {
            cout << "Cannot withdraw! Minimum balance of " << minimumBalance << " must be maintained." << endl;
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Minimum Balance Requirement: " << minimumBalance << endl;
    }
};

// Derived class for FixedDepositAccount
class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(int accNum, string holderName, double initialBalance, double fixedRate, string maturity)
        : Account(accNum, holderName, initialBalance, "Fixed Deposit"), fixedInterestRate(fixedRate), maturityDate(maturity) {}

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100);
        balance += interest;
        cout << "Interest of " << interest << " added. New balance: " << balance << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main() {
    // Create accounts for testing
    SavingsAccount savings(1001, "John Doe", 1500.0, 5.0);
    CheckingAccount checking(1002, "Jane Smith", 3000.0, 500.0);
    FixedDepositAccount fixedDeposit(1003, "Alice Brown", 10000.0, 7.0, "2027-12-31");

    // Test Deposit, Withdraw, and Interest Calculation
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateInterest();
    savings.printStatement();

    checking.deposit(1000.0);
    checking.withdraw(1000.0);
    checking.printStatement();

    fixedDeposit.deposit(2000.0);
    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();

    return 0;
}
