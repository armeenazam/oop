#include <iostream>
#include <string>
using namespace std;

class LoanHelper {
private:
    const float interestRate;
    float loanAmount;
    int months;
    float repayAmount;

public:
    LoanHelper() : interestRate(0.0), loanAmount(0.0), months(0), repayAmount(0.0) {}

    LoanHelper(float rate, float amount, int m)
        : interestRate(rate), loanAmount(amount), months(m), repayAmount(0.0) {}

    void calculateRepay() {
        float baseRepayment = loanAmount / months;
        repayAmount = baseRepayment + (baseRepayment * interestRate);
    }

    void displayRepayment() {
        cout << "You have to pay " << repayAmount 
             << " every month for " << months << " months to repay your loan." << endl;
    }

    static bool isValidInterestRate(float rate) {
        return rate >= 0.0 && rate <= 0.005;  
    }
};

int main() {
    float rate, amount;
    int months;

    cout << "Enter the interest rate (as a decimal, e.g., 0.01 for 1%): ";
    cin >> rate;
    if (!LoanHelper::isValidInterestRate(rate)) {
        cout << "Invalid interest rate. Please enter a rate between 0 and 0.5%." << endl;
        return 1;
    }

    cout << "Enter the loan amount: ";
    cin >> amount;
    cout << "Enter the number of months to repay the loan: ";
    cin >> months;

    LoanHelper loan(rate, amount, months);
    loan.calculateRepay();
    loan.displayRepayment();

    return 0;
}
