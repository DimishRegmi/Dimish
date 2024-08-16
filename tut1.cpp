#include <iostream>
#include <string>

using namespace std;

class ATM {
private:
    string username;
    string password;
    double balance;

public:
    ATM(string user, string pass, double initial_balance) {
        username = user;
        password = pass;
        balance = initial_balance;
    }

    bool authenticate(string user, string pass) {
        return username == user && password == pass;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void checkBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
    ATM myATM("user123", "pass123", 1000.0);

    string user, pass;
    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    if (myATM.authenticate(user, pass)) {
        int choice;
        do {
            cout << "\nATM Menu:\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    myATM.checkBalance();
                    break;
                case 2:
                    double depositAmount;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmount;
                    myATM.deposit(depositAmount);
                    break;
                case 3:
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;
                    myATM.withdraw(withdrawAmount);
                    break;
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    } else {
        cout << "Authentication failed. Exiting program." << endl;
    }

    return 0;
}
