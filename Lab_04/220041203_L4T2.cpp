
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int acc_Num;
    string acc_Holder;
    string acc_Type;
    double currentBalance;
    const double minimumBalance;

public:
    static int totalAccounts;
    static int currentAccounts;
    static double totalSourceTax;

    BankAccount(int accNum, string accHolder, string accType, double balance, double minBalance)
        : acc_Num(accNum), acc_Holder(accHolder), acc_Type(accType), currentBalance(balance), minimumBalance(minBalance) {
        totalAccounts++;
        currentAccounts++;
    }

    ~BankAccount() {
        cout << "Account of Mr./Ms. " << acc_Holder << " with account no " << acc_Num << " is destroyed with a balance BDT " << currentBalance << endl;
        currentAccounts--;
    }

    void showAllInfo() const {
        cout << "Account Number: " << acc_Num << endl;
        cout << "Account Holder Name: " << acc_Holder << endl;
        cout << "Account Type: " << acc_Type << endl;
        cout << "Current Balance: " << currentBalance << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
        cout<<"---------------------------"<<endl;
    }

    void showBalance() const {
        cout << "Current Balance: " << currentBalance << endl;
       // cout<<"---------------------------------------------------------------"<<endl;

    }

    void deposit(double amount) {
        if (amount > 0)
            currentBalance += amount;
        else
            cout << "Invalid deposit amount." << endl;
    }

    void withdrawal(double amount) {
        if (amount > 0 && currentBalance - amount >= minimumBalance)
            currentBalance -= amount;
        else
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
    }

    void giveInterest(double interestRate = 3.0) {
        double interest = currentBalance * (interestRate / 100.0);
        double sourceTax = interest * 0.10;
        totalSourceTax += sourceTax;
        currentBalance += (interest - sourceTax);
    }

    double getCurrentBalance() const {
        return currentBalance;
    }

    string getAccountHolder() const {
        return acc_Holder;
    }

   // friend void display_stat();
   // friend void compareAccounts(const BankAccount& acc1, const BankAccount& acc2);
};

int BankAccount::totalAccounts = 0;
int BankAccount::currentAccounts = 0;
double BankAccount::totalSourceTax = 0.0;

void display_stat() {
    cout << "Total Bank Accounts Created: " << BankAccount::totalAccounts << endl;
    cout << "Current Bank Accounts: " << BankAccount::currentAccounts << endl;
    cout << "Total Source Tax Collected: " << BankAccount::totalSourceTax << endl;
    cout<<"---------------------------------------------------------------"<<endl;
}

void compareAccounts(const BankAccount& acc1, const BankAccount& acc2) {
    const BankAccount& largerAccount = (acc1.getCurrentBalance() > acc2.getCurrentBalance()) ? acc1 : acc2;
    cout << "Larger Account Holder: " << largerAccount.getAccountHolder() << endl;
}

int main() {
    BankAccount acc1(245, "Wasi Vaiya", "Savings", 5000.0, 1000.0);
    BankAccount acc2(203, "Lihan", "Current", 3000.0, 500.0);

    acc1.showAllInfo();
    acc2.showAllInfo();

    acc1.deposit(1000);
    acc1.withdrawal(2000);
    acc1.giveInterest();
    acc1.showBalance();

    acc2.deposit(500);
    acc2.withdrawal(1000);
    acc2.giveInterest(5.0);
    acc2.showBalance();

    display_stat();
    compareAccounts(acc1, acc2);

    return 0;
}
