// You are building a bank account management system. Create a class `Account` to manage bank
// accounts.
// Requirements:
// 1. Attributes:
//  `accountNumber` (string)
//  `accountHolderName` (string)
//  `balance` (double)
// 2. Define a default constructor that initializes `balance` to `0.0`.
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:
//  `deposit(double amount)`: Adds the amount to the balance.
//  `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
// available).
//  `checkBalance()`: Displays the current balance.
// 5. Create a few `Account` objects and test the methods.

#include<iostream>
#include<string>
using namespace std;

class Account{
private:    
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(){
        this->balance = 0.0;
    }

    Account(string accountNumber, string accountHolderName, double balance){
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    double deposit (double amount){
        balance += amount ;
        cout<<"Rs. "<<amount<<" deposited"<<endl;

        return balance;


    }

    double withdraw (double amount){
        if(amount < balance){
            balance -= amount;
            cout<<"Rs. "<<amount<<" withdrawn"<<endl;
            return balance;
        }
        else {
            cout<<"Insufficient balance. Please enter a valid amount"<<endl;
            return balance;
        }

    }

    void checkBalance (){
        cout<<"Current Balance = "<< balance <<endl;
    }
        
};

int main()
{
    Account a1("AX128782-09" , "Armeen" , 200000.0);
    Account a2("QW474768-70" , "Ariza" , 1000000.0);
    Account a3("TY198764-54" , "Arman" , 200.0);

     int choice;
    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            double depositAmount;
            cout << "Enter the amount to be deposited :" <<endl;
            cin>>depositAmount;
            a1.deposit(depositAmount);
            a2.deposit(depositAmount);
            a3.deposit(depositAmount);
            break;

            case 2:
            double withdrawAmount;
            cout << "Enter the amount to be withdrawn :" <<endl;
            cin>>withdrawAmount;
            a1.withdraw(withdrawAmount);
            a2.withdraw(withdrawAmount);
            a3.withdraw(withdrawAmount);
            break;

            case 3:
            a1.checkBalance();
            a2.checkBalance();
            a3.checkBalance();
            break;

            case 4:
            cout << "Exiting the system..." <<endl;
            return 0;

            default:
            cout<<"invalid choice"<<endl;
        }
    }while(choice!=4);

    return 0;

}