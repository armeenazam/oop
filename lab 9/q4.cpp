#include <iostream>
#include <string>

using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
    
public:
    CreditCard(const string& cardNum) : cardNumber(cardNum) {}
    
    void processPayment(double amount) override {
        if (cardNumber.empty()) {
            cout << "Invalid card number." << endl;
            return;
        }
        cout << "Processing credit card payment of $" << amount << " with card " << cardNumber << endl;
        cout << "Payment successful!" << endl;
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;
    
public:
    DigitalWallet(double initialBalance) : balance(initialBalance) {}
    
    void processPayment(double amount) override {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Processing digital wallet payment of $" << amount << endl;
        cout << "Remaining balance: $" << balance << endl;
        cout << "Payment successful!" << endl;
    }
};

int main() {
    CreditCard myCard("1234-5678-9876-5432");
    DigitalWallet myWallet(100.0);
    
    cout << "Simulating Credit Card Payment:" << endl;
    myCard.processPayment(50.0);
    
    cout << "\nSimulating Digital Wallet Payment:" << endl;
    myWallet.processPayment(30.0);
    
    cout << "\nSimulating Insufficient Balance in Wallet:" << endl;
    myWallet.processPayment(80.0);

    return 0;
}
