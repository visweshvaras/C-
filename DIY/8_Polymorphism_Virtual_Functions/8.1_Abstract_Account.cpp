// DIY 8.1: Abstract Account Runtime Polymorphism
// Lab Manual Page 28: Pure-virtual calculateInterest(); derive Savings and Current with different rates; process an array of Account*.
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNo, double bal) : accountNumber(accNo), balance(bal) {}
    virtual ~Account() = default;

    virtual double calculateInterest() const = 0; // Pure virtual

    virtual void display() const {
        cout << "Acc #" << accountNumber << " | Balance: Rs. " << fixed << setprecision(2) << balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate; // e.g. 4.5%

public:
    SavingsAccount(int accNo, double bal, double rate = 4.5) 
        : Account(accNo, bal), interestRate(rate) {}

    double calculateInterest() const override {
        return balance * (interestRate / 100.0);
    }

    void display() const override {
        Account::display();
        cout << " | Type: Savings (Rate: " << interestRate << "%) | Interest: Rs. " 
             << calculateInterest() << endl;
    }
};

class CurrentAccount : public Account {
private:
    double interestRate; // e.g. 1.0%

public:
    CurrentAccount(int accNo, double bal, double rate = 1.0) 
        : Account(accNo, bal), interestRate(rate) {}

    double calculateInterest() const override {
        return balance * (interestRate / 100.0);
    }

    void display() const override {
        Account::display();
        cout << " | Type: Current (Rate: " << interestRate << "%) | Interest: Rs. " 
             << calculateInterest() << endl;
    }
};

int main() {
    cout << "=== DIY 8.1: Abstract Account and Polymorphic Interest Processing ===" << endl;

    vector<Account*> portfolio;
    portfolio.push_back(new SavingsAccount(1001, 75000.0, 4.5));
    portfolio.push_back(new CurrentAccount(2001, 150000.0, 1.2));
    portfolio.push_back(new SavingsAccount(1002, 32000.0, 5.0));

    double totalInterest = 0;
    cout << "\nProcessing Accounts Polymorphically:" << endl;
    for (Account* acc : portfolio) {
        acc->display();
        totalInterest += acc->calculateInterest();
    }

    cout << "\nTotal Annual Interest Disbursed: Rs. " << fixed << setprecision(2) << totalInterest << endl;

    for (Account* acc : portfolio) {
        delete acc;
    }

    return 0;
}
