#include <iostream>
#include <map>

#include"member.h"
#include"normal_member.h"
#include"silver_member.h"
#include"gold_member.h"
#include"diamond_member.h"

using namespace std;

//member class
member::member(int initId, string initName, string initPhoneNumber, int initTotalTransaction)
{
    id = initId;
    name = initName;
    phoneNumber = initPhoneNumber;
    totalTransaction = initTotalTransaction;
}

void member::print()
{
    cout << "ID: " << id << "\n"
        << "Name: " << name << "\n"
        << "Phone: " << phoneNumber << "\n"
        << "Total Transaction: " << totalTransaction << "\n";
}

//normal member class
normalMember::normalMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction) :member(initId, initName, initPhoneNumber, initTotalTransaction) {}

void normalMember::print()
{
    cout << "- NORMAL MEMBERSHIP -\n";
    member::print();
    cout << " -MEMBER BENERFITS- \n"
        << "discount: " << discount * 100 << "%\n"
        << "Exclusive items per month: " << exclusiveItemsPM << "\n"
        << "Exclusive items per year: " << exclusiveItemsPY << "\n"
        << "Food Voucher per month: " << foodVoucher << "\n";
}

//silver member class
silverMember::silverMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction) :member(initId, initName, initPhoneNumber, initTotalTransaction) {}

void silverMember::print()
{
    cout << "- SILVER MEMBERSHIP -\n";
    member::print();
    cout << " -MEMBER BENERFITS- \n"
        << "discount: " << discount * 100 << "%\n"
        << "Exclusive items per month: " << exclusiveItemsPM << "\n"
        << "Exclusive items per year: " << exclusiveItemsPY << "\n"
        << "Food Voucher per month: " << foodVoucher << "\n";
}

//gold member class
goldMember::goldMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction) :member(initId, initName, initPhoneNumber, initTotalTransaction) {}

void goldMember::print()
{
    cout << "- GOLD MEMBERSHIP -\n";
    member::print();
    cout << " -MEMBER BENERFITS- \n"
        << "discount: " << discount * 100 << "%\n"
        << "Exclusive items per month: " << exclusiveItemsPM << "\n"
        << "Exclusive items per year: " << exclusiveItemsPY << "\n"
        << "Food Voucher per month: " << foodVoucher << "\n";
}

//diamond member class
diamondMember::diamondMember(int initId, string initName, string initPhoneNumber, int initTotalTransaction) :member(initId, initName, initPhoneNumber, initTotalTransaction) {}

void diamondMember::print()
{
    cout << "- DIAMOND MEMBERSHIP -\n";
    member::print();
    cout << " -MEMBER BENERFITS- \n"
        << "discount: " << discount * 100 << "%\n"
        << "Exclusive items per month: " << exclusiveItemsPM << "\n"
        << "Exclusive items per year: " << exclusiveItemsPY << "\n"
        << "Food Voucher per month: " << foodVoucher << "\n";
}

int main()
{
    int id;
    map<int, member*>memberlist;
    memberlist[111] = new normalMember (111, "Peter" , "0901234567", 24);
    memberlist[333] = new silverMember (333, "Tobey" , "0907654321", 45);
    memberlist[555] = new goldMember   (555, "Andrew", "0907654123", 67);
    memberlist[777] = new diamondMember(777, "Tom"   , "0905674321", 93);

    cout << "Member ID: ";
    while (cin >> id)
    {
        if (memberlist.find(id) != memberlist.end())
            memberlist[id]->print();
        else
            cout << "Member ID not found.\n";
        cout << "\nMember ID: ";
    }
}