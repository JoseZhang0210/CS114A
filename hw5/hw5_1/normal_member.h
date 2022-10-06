using namespace std;

#ifndef NORMAL_MEMBER_H
#define NORMAL_MEMBER_H

class normalMember :public member
{
public:
	normalMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction);
	void print();
private:
	const double discount=0.05;
	const int exclusiveItemsPM = 0;
	const int foodVoucher = 0;
	const int exclusiveItemsPY = 0;
};
#endif
