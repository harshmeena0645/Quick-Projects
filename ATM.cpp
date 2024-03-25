#include <iostream>
#include <string>
#include <map>

using namespace std;

class Bank {
private:
    map<string, double> accounts;

public:
    void createAccount(string name, double initialBalance) {
        accounts[name] = initialBalance;
        cout << "Account created successfully for " << name << ". Initial balance: " << initialBalance << endl;
    }

    void deposit(string name, double amount) {
        accounts[name] += amount;
        cout << "Deposit successful. Current balance for " << name << ": " << accounts[name] << endl;
    }

    void withdraw(string name, double amount) {
        if (accounts[name] >= amount) {
            accounts[name] -= amount;
            cout << "Withdrawal successful. Current balance for " << name << ": " << accounts[name] << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    double getBalance(string name) {
        return accounts[name];
    }
};

int main() {
    Bank bank;
    int choice;
    string name;
    double amount;

    while (true) {
        cout << "\nATM Menu\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> amount;
                bank.createAccount(name, amount);
                break;
            case 2:
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(name, amount);
                break;
            case 3:
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(name, amount);
                break;
            case 4:
                cout << "Enter your name: ";
                cin >> name;
                cout << "Current balance for " << name << ": " << bank.getBalance(name) << endl;
                break;
            case 5:
                cout << "Exiting program. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
