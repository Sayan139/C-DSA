#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    string name;
    double balance;

    Account(int accNumber, string accHolderName, double initialBalance)
        : accountNumber(accNumber), name(accHolderName), balance(initialBalance) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber
             << " | Name: " << name
             << " | Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New Balance: $" << balance << endl;
        } else {
            cout << "Invalid amount. Deposit failed.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New Balance: $" << balance << endl;
        } else {
            cout << "Invalid or insufficient funds. Withdrawal failed.\n";
        }
    }
};

class BankManagementSystem {
private:
    vector<Account> accounts;
    int nextAccountNumber;

public:
    BankManagementSystem() : nextAccountNumber(1001) {}

    void createAccount(string name, double initialDeposit) {
        if (initialDeposit < 0) {
            cout << "Initial deposit cannot be negative. Account creation failed.\n";
            return;
        }
        accounts.push_back(Account(nextAccountNumber, name, initialDeposit));
        cout << "Account created successfully. Account Number: " << nextAccountNumber << endl;
        nextAccountNumber++;
    }

    void displayAccounts() {
        if (accounts.empty()) {
            cout << "No accounts in the system.\n";
            return;
        }
        for (auto& account : accounts) {
            account.displayDetails();
        }
    }

    void depositAmount(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                account.deposit(amount);
                return;
            }
        }
        cout << "Account Number " << accountNumber << " not found.\n";
    }

    void withdrawAmount(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                account.withdraw(amount);
                return;
            }
        }
        cout << "Account Number " << accountNumber << " not found.\n";
    }

    void checkBalance(int accountNumber) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                cout << "Account Balance: $" << account.balance << endl;
                return;
            }
        }
        cout << "Account Number " << accountNumber << " not found.\n";
    }
};

int main() {
    BankManagementSystem bms;
    int choice, accountNumber;
    string name;
    double amount;

    while (true) {
        cout << "\nBank Management System Menu\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Account Holder Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Initial Deposit Amount: ";
            cin >> amount;
            bms.createAccount(name, amount);
            break;

        case 2:
            bms.displayAccounts();
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            bms.depositAmount(accountNumber, amount);
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            bms.withdrawAmount(accountNumber, amount);
            break;

        case 5:
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            bms.checkBalance(accountNumber);
            break;

        case 6:
            cout << "Exiting system.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
