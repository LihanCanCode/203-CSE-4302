
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
        string Name;
        int acc_Number;
        string acc_Type;
        double balanceAmount;

    public:
        // Constructor
        BankAccount() : balanceAmount(0.0) {}

        void customerDetails(const string& name, int accNumber) {
            Name = name;
            acc_Number = accNumber;
        }

        void accountType(const string& type) {
            if (type == "Current" || type == "Saving")
                acc_Type = type;
             else
                cout << "Invalid account type. Assign 'Current' or 'Saving'." << endl;
        }

        void balance() const {
            cout << "Balance amount: " << balanceAmount << endl;
        }


        void deposit(double amount) {
            if (amount > 0) {
                balanceAmount += amount;
                //cout << "Amount deposited: " << amount << endl;
                cout << "New balance: " << balanceAmount << endl;
            } else
                cout << "Invalid deposit amount." << endl;
        }

        void withdraw(double amount) {
            if (amount > 0 && amount <= balanceAmount) {
                balanceAmount -= amount;
                cout << "Amount withdrawn: " << amount << endl;
                cout << "New balance: " << balanceAmount << endl;
            } else
                cout << "Invalid or insufficient funds for withdrawal." << endl;

        }

        void display() const {
            cout << "\nCustomer Name: " << Name << endl;
            cout << "Account Number: " << acc_Number << endl;
            cout << "Account Type: " << acc_Type << endl;
            cout << "Balance Amount: " << balanceAmount << endl;
        }
};

int main() {
    BankAccount customer;

    customer.customerDetails("Lihan", 220041203);
    customer.accountType("Saving");
    customer.deposit(2000.0);
    customer.withdraw(500.0);
    customer.balance();
    customer.display();



    return 0;
}
