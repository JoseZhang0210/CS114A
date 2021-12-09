using namespace std;

#ifndef SILVER_MEMBER_H
#define SILVER_MEMBER_H

class silverMember :public member
{
public:
	silverMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction);
	void print();
private:
	const double discount = 0.1;
	const int exclusiveItemsPM = 1;
	const int foodVoucher = 0;
	const int exclusiveItemsPY = 0;
};
#endif