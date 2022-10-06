using namespace std;

#ifndef MEMBER_H
#define MEMBER_H

class member
{
public:
	member(int initId,string initName,string initPhoneNumber,int initTotalTransaction);
	virtual void print();
private:
	int id;
	string name;
	string phoneNumber;
	int totalTransaction;
};
#endif
