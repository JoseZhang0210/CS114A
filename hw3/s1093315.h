using namespace std;
#ifndef H_S1093315
#define H_S1093315

//you can not add other functions in the class Account
class Account
{
public:
	Account(double = 0.0, double = 0.0);
	void credit(double = 0.0);//Deposit money >0
	bool debit(double = 0.0);//Withdraw money >0
	double getBalance();//Get balance
	double calculateInterest();//Ruturn interest and add the interest to the balance
	void print();//Print balance and interest rate
private:
	double balance;//Account balance >=0
	double interestRate;//Interest rate>=0
};

class CheckingAccount;

class SavingAccount:public Account
{
public:
	SavingAccount(double = 0.0, double = 0.0, double = 3.0);//Parameter:balance, interest rate, transaction fee
	bool debit(double = 0.0);
	void print();
	friend bool CheckingToSaving(CheckingAccount&, SavingAccount&, const double);
	friend bool SavingToChecking(SavingAccount&, CheckingAccount&, const double);
private:
	double transactFee;//Transaction fee for withdrawing
};

class CheckingAccount:public Account
{
public:
	CheckingAccount(double = 0.0, double = 0.0, double = 3.0, double = 2.0);
	//Parameters:blance, interest rate, transaction fee for withdraw, transaction fee for deposition
	bool debit(double = 0.0);//return true if it can be done successfully
	void credit(double = 0.0);
	void print();
	friend bool CheckingToSaving(CheckingAccount&, SavingAccount&, const double);
	friend bool SavingToChecking(SavingAccount&, CheckingAccount&, const double);
private:
	double transactFeeW;//withdraw 
	double transactFeeD;//deposit
};

#endif



