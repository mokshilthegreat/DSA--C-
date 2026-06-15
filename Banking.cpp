#include <iostream>
using namespace std;

// Base Class
class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "\nAmount Deposited Successfully!";
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "\nAmount Withdrawn Successfully!";
        }
        else
        {
            cout << "\nInsufficient Balance!";
        }
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double bal)
    {
        balance = bal;
    }

    virtual void displayAccountInfo()
    {
        cout << "\n\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolderName;
        cout << "\nBalance        : " << balance << endl;
    }

    virtual void calculateInterest()
    {
        cout << "\nNo Interest Available";
    }
};

// Savings Account
class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name,
                   double bal, double rate)
        : BankAccount(accNo, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest;

        interest = (getBalance() * interestRate) / 100;

        cout << "\nSavings Interest : "
             << interest << endl;
    }
};

// Checking Account
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name,
                    double bal, double limit)
        : BankAccount(accNo, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override
    {
        if (amount <= (getBalance() + overdraftLimit))
        {
            setBalance(getBalance() - amount);

            cout << "\nAmount Withdrawn Successfully!";
        }
        else
        {
            cout << "\nOverdraft Limit Exceeded!";
        }
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name,
                        double bal, int t, double rate)
        : BankAccount(accNo, name, bal)
    {
        term = t;
        interestRate = rate;
    }

    void calculateInterest() override
    {
        double interest;

        interest = (getBalance() *
                    interestRate *
                    term) /
                   (100 * 12);

        cout << "\nFD Interest : "
             << interest << endl;
    }
};

int main()
{
    SavingsAccount s1(101, "Kaku", 5000, 5);

    CheckingAccount c1(102, "Riya", 7000, 3000);

    FixedDepositAccount f1(103, "Jay", 10000, 12, 6);

    BankAccount *ptr;

    int choice;

    do
    {
        cout << "\n\n===== BANKING SYSTEM =====";

        cout << "\n1. Savings Account";
        cout << "\n2. Checking Account";
        cout << "\n3. Fixed Deposit Account";
        cout << "\n4. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            ptr = &s1;

            int ch;
            double amount;

            do
            {
                cout << "\n\n--- Savings Account ---";

                cout << "\n1. Deposit";
                cout << "\n2. Withdraw";
                cout << "\n3. Check Balance";
                cout << "\n4. Calculate Interest";
                cout << "\n5. Display Info";
                cout << "\n6. Back";

                cout << "\n\nEnter Choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "\nEnter Amount : ";
                    cin >> amount;

                    ptr->deposit(amount);
                    break;

                case 2:
                    cout << "\nEnter Amount : ";
                    cin >> amount;

                    ptr->withdraw(amount);
                    break;

                case 3:
                    cout << "\nBalance : "
                         << ptr->getBalance();
                    break;

                case 4:
                    ptr->calculateInterest();
                    break;

                case 5:
                    ptr->displayAccountInfo();
                    break;
                }

            } while (ch != 6);

            break;
        }

        case 2:
        {
            ptr = &c1;

            int ch;
            double amount;

            do
            {
                cout << "\n\n--- Checking Account ---";

                cout << "\n1. Deposit";
                cout << "\n2. Withdraw";
                cout << "\n3. Check Balance";
                cout << "\n4. Display Info";
                cout << "\n5. Back";

                cout << "\n\nEnter Choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "\nEnter Amount : ";
                    cin >> amount;

                    ptr->deposit(amount);
                    break;

                case 2:
                    cout << "\nEnter Amount : ";
                    cin >> amount;

                    ptr->withdraw(amount);
                    break;

                case 3:
                    cout << "\nBalance : "
                         << ptr->getBalance();
                    break;

                case 4:
                    ptr->displayAccountInfo();
                    break;
                }

            } while (ch != 5);

            break;
        }

        case 3:
        {
            ptr = &f1;

            int ch;
            double amount;

            do
            {
                cout << "\n\n--- Fixed Deposit Account ---";

                cout << "\n1. Deposit";
                cout << "\n2. Withdraw";
                cout << "\n3. Check Balance";
                cout << "\n4. Calculate Interest";
                cout << "\n5. Display Info";
                cout << "\n6. Back";

                cout << "\n\nEnter Choice : ";
                cin >> ch;

                switch (ch)
                {
                case 1:
                    cout << "\nEnter Amount : ";
                    cin >> amount;

                    ptr->deposit(amount);
                    break;

                case 2:
                    cout << "\nEnter Amount : ";
                    cin >> amount;

                    ptr->withdraw(amount);
                    break;

                case 3:
                    cout << "\nBalance : "
                         << ptr->getBalance();
                    break;

                case 4:
                    ptr->calculateInterest();
                    break;

                case 5:
                    ptr->displayAccountInfo();
                    break;
                }

            } while (ch != 6);

            break;
        }

        case 4:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}