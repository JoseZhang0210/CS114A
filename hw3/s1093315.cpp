#include "s1093315.h"

Account::Account(double init_balance, double init_interestRate)
{
    balance = init_balance;
    interestRate = init_interestRate;
}

void Account::credit(double credit_amount)
{
    balance += credit_amount;
}

bool Account::debit(double debit_amount)
{
    if (debit_amount > balance)
        return false;
    balance -= debit_amount;
    return true;
}

double Account::getBalance()
{
    return balance;
}

double Account::calculateInterest()
{
    static double interest = 0;
    interest = balance * interestRate;
    balance += interest;
    return interest;
}

void Account::print()
{
    cout << "    Balance: " << balance << "\n" 
         << "    Interest rate: " << interestRate << "\n";
}

SavingAccount::SavingAccount(double init_balance, double init_interestRate, double init_transactFee):Account(init_balance, init_interestRate)
{
    transactFee = init_transactFee;
}

bool SavingAccount::debit(double debit_amount)
{
    if (Account::debit(debit_amount + transactFee))
        return true;
    cout << "Debit amount exceeded account balance.\n";
    return false;
}

void SavingAccount::print()
{
    cout << "SavingAccount account:\n";
    Account::print();
    cout << "    Transaction fee of withdraw:" << transactFee << "\n";
}

CheckingAccount::CheckingAccount(double init_balance, double init_interestRate, double init_transactFeeW, double init_transactFeeD) :Account(init_balance, init_interestRate)
{
    transactFeeW = init_transactFeeW;
    transactFeeD = init_transactFeeD;
}

bool CheckingAccount::debit(double debit_amount)
{
    if (Account::debit(debit_amount + transactFeeW))
        return true;
    cout << "Debit amount exceeded account balance.\n";
    return false;
}

void CheckingAccount::credit(double credit_amount)
{
    Account::credit(credit_amount - transactFeeD);
}

void CheckingAccount::print()
{
    cout << "CheckingAccount account:\n";
    Account::print();
    cout << "    Transaction fee of withdraw:" << transactFeeW << "\n";
    cout << "    Transaction fee of deposition:" << transactFeeD << "\n";
}

bool CheckingToSaving(CheckingAccount& cAcnt, SavingAccount& sAcnt, const double transfer_amount)
{
    if (cAcnt.Account::debit(transfer_amount + cAcnt.transactFeeW))
    {
        sAcnt.credit(transfer_amount);
        return true;
    }
    else
    {
        cout << "Transfer transaction fails.\n";
        return false;
    }
}

bool SavingToChecking(SavingAccount& sAcnt, CheckingAccount& cAcnt, const double transfer_amount)
{
    if (sAcnt.Account::debit(transfer_amount + sAcnt.transactFee))
    {
        cAcnt.credit(transfer_amount);
        return true;
    }
    else
    {
        cout << "Transfer transaction fails.\n";
        return false;
    }
}