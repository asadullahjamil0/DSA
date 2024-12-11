#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string holder, double initialBalance = 0) : accountHolder(holder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". Remaining balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void accountDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string holder, double initialBalance, double rate)
        : BankAccount(holder, initialBalance), interestRate(rate) {}

    void addInterest() {
        double interest = getBalance() * interestRate;
        deposit(interest);
        cout << "Interest added: $" << interest << ". New balance: $" << getBalance() << endl;
    }
};

class Customer {
private:
    string name;
    vector<BankAccount*> accounts;

public:
    Customer(string customerName) : name(customerName) {}

    void addAccount(BankAccount* account) {
        accounts.push_back(account);
    }

    void viewAccounts() const {
        cout << name << "'s Accounts:" << endl;
        for (const auto& account : accounts) {
            account->accountDetails();
        }
    }
};

int main() {
    Customer customer("John Doe");

    BankAccount checkingAccount("John Doe", 1000);
    SavingsAccount savingsAccount("John Doe", 5000, 0.03);

    customer.addAccount(&checkingAccount);
    customer.addAccount(&savingsAccount);

    customer.viewAccounts();

    checkingAccount.deposit(500);
    checkingAccount.withdraw(200);

    savingsAccount.addInterest();

    customer.viewAccounts();

    return 0;
}
