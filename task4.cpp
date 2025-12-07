#include <iostream>
#include <vector>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) : type(t), amount(a) {}
};

class Account {
public:
    string accNo;
    double balance;
    vector<Transaction> history;

    Account(string acc) : accNo(acc), balance(0) {}

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        history.push_back(Transaction("Withdraw", amount));
        return true;
    }

    void transfer(Account &to, double amount) {
        if (withdraw(amount)) {
            to.deposit(amount);
            history.push_back(Transaction("Transfer to " + to.accNo, amount));
        }
    }

    void showHistory() {
        cout << "\nTransaction History for " << accNo << ":\n";
        for (auto &t : history)
            cout << t.type << " — Rs." << t.amount << endl;
    }
};

int main() {
    Account a1("A1001");
    Account a2("A2001");

    a1.deposit(5000);
    a1.withdraw(1200);
    a1.transfer(a2, 2000);

    cout << "\nBalance A1001: " << a1.balance;
    cout << "\nBalance A2001: " << a2.balance << "\n";

    a1.showHistory();
    a2.showHistory();

    return 0;
}
