using namespace std;

#ifndef DIAMOND_MEMBER_H
#define DIAMOND_MEMBER_H

class diamondMember :public member
{
public:
	diamondMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction);
	void print();
private:
	const double discount = 0.2;
	const int exclusiveItemsPM = 2;
	const int foodVoucher = 1;
	const int exclusiveItemsPY = 1;
};
#endif