using namespace std;

#ifndef GOLD_MEMBER_H
#define GOLD_MEMBER_H

class goldMember :public member
{
public:
	goldMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction);
	void print();
private:
	const double discount = 0.15;
	const int exclusiveItemsPM = 1;
	const int foodVoucher = 1;
	const int exclusiveItemsPY = 0;
};
#endif