#include <iostream>
#include "s1093315.cpp"

using namespace std;

double money, rate;
int main()
{
    cin >> money >> rate;
    cout << "Create a saving account." << endl;
    SavingAccount sAcnt(money, rate);
    sAcnt.print();
    sAcnt.debit(50.0);
    cout << "    New balance after withdrawing $50 from the saving account:" << sAcnt.getBalance() << endl;
    sAcnt.credit(150.0);
    cout << "    New balance after depositing $150 to the saving account:" << sAcnt.getBalance() << endl;
    sAcnt.print();
    cout << "    Interest of the saving account:" << sAcnt.calculateInterest() << endl;
    cout << "    New balance after adding interest:" << sAcnt.getBalance() << endl;
    cout << "    Withdrawing 800 from the saving account:" << endl;
    sAcnt.debit(800);

    cin >> money >> rate;
    cout << "\nCreate a checking account." << endl;
    CheckingAccount cAcnt(money, rate);
    cAcnt.print();
    cAcnt.debit(200.0);
    cout << " New balance after withdrawing $200 from the checking account:" << cAcnt.getBalance() << endl;
    cAcnt.credit(150.0);
    cout << " New balance after depositing $150 to the checking account:" << cAcnt.getBalance() << endl;

    cout << endl;
    cAcnt.print();
    sAcnt.print();

    cout << "\nAfter transfer $600 from cAcnt to sAcnt:" << endl;
    CheckingToSaving(cAcnt, sAcnt, 600.0);
    cout << "New balance of cAcnt:" << cAcnt.getBalance() << " New balance of sAcnt " << sAcnt.getBalance() << endl;
    cout << "\nAfter transfer $800 from sAcnt to sAcnt" << endl;
    SavingToChecking(sAcnt, cAcnt, 800.0);
    cout << "New balance of cAcnt:" << cAcnt.getBalance() << " New balance of sAcnt " << sAcnt.getBalance() << endl;
    CheckingToSaving(cAcnt, sAcnt, 50.0);
    cout << "\nAfter transfer $50 from cAcnt to sAcnt" << endl;
    cout << "New balance of cAcnt:" << cAcnt.getBalance() << " New balance of sAcnt " << sAcnt.getBalance() << endl;
    SavingToChecking(sAcnt, cAcnt, 50.0);
    cout << "\nAfter transfer $50 from sAcnt to cAcnt" << endl;
    cout << "New balance of cAcnt:" << cAcnt.getBalance() << " New balance of sAcnt " << sAcnt.getBalance() << endl;
}