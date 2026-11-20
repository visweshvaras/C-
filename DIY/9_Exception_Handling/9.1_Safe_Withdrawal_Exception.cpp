// DIY 9.1: Safe Withdrawal with Custom InsufficientFundsException
// Lab Manual Page 31: Extend the Week-3 BankAccount to throw a custom InsufficientFunds exception instead of returning false.
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class InsufficientFundsException : public exception {
private:
    string message;
    double currentBalance;
    double requestedAmount;

public:
    InsufficientFundsException(double bal, double req) 
        : currentBalance(bal), requestedAmount(req) {
        message = "InsufficientFundsException: Attempted to withdraw Rs. " + 
                  to_string(req) + " but balance is only Rs. " + to_string(bal);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    double getDeficit() const { return requestedAmount - currentBalance; }
};

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(const string &name, double initBal) 
        : owner(name), balance(initBal) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException(balance, amount);
        }
        balance -= amount;
        cout << "Withdrawal successful: Rs. " << amount << " | New Balance: Rs. " << balance << endl;
    }

    double getBalance() const { return balance; }
};

int main() {
    cout << "=== DIY 9.1: Safe Withdrawal with Custom Exception ===" << endl;

    BankAccount acc("Alice", 5000.0);
    cout << "Initial balance: Rs. " << acc.getBalance() << endl;

    try {
        cout << "\nAttempting valid withdrawal of Rs. 2000:" << endl;
        acc.withdraw(2000.0);

        cout << "\nAttempting invalid withdrawal of Rs. 4000 (exceeds balance of 3000):" << endl;
        acc.withdraw(4000.0);
    } catch (const InsufficientFundsException &e) {
        cout << "Caught Exception: " << e.what() << endl;
        cout << "Shortage amount: Rs. " << e.getDeficit() << endl;
    }

    return 0;
}
