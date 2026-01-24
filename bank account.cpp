#include <iostream>
using namespace std;

class BankAccount {
private:
    float balance;

public:
    BankAccount(float b) {
        balance = b;
    }

    friend class AccountManager;
};

class AccountManager {
public:
    void display(BankAccount &b1) {
        cout << "Current Balance: " << b1.balance << endl;
    }

    void addMoney(BankAccount &b1, float amount) {
        b1.balance += amount;
        cout << "Amount Added Successfully\n";
    }

    void deductMoney(BankAccount &b1, float amount) {
        if (amount <= b1.balance) {
            b1.balance -= amount;
            cout << "Amount Deducted Successfully\n";
        } else {
            cout << "Insufficient Balance\n";
        }
    }
};

int main() {
    BankAccount b1(5000);
    AccountManager manager;

    manager.display(b1);
    manager.addMoney(b1, 2000);
    manager.display(b1);
    manager.deductMoney(b1, 3000);
    manager.display(b1);

    return 0;
}
