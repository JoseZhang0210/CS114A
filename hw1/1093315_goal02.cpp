#include <iostream>
#include <string>
#include <iomanip>
#include "1093315_goal02.h"
using namespace std;

Time::Time()
{
    hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printUniversal()
{
    cout << setfill('0') << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second;
}

void Time::printStandard()
{
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ':' << setfill('0') << setw(2) << minute << ':' << setw(2) << second << (hour < 12 ? " AM" : " PM");
}

void Time::printNumber(string str)
{
    //Goal 04 check
    bool anyalpha = 0;
    for (int i = 0;i < str.size();i++)
        if (str[i] != ':' && isalpha(str[i]))
        {
            anyalpha = 1;
            break;
        }

    //string -> time's data member
    if (anyalpha)
    {
        string newStr;
        cout << "\n Error!!!\nPlease enter again:\n";
        getline(cin, newStr);
        printNumber(newStr);
    }
    else
    {
        hour = (str[0]-'0') * 10;
        hour += str[1] - '0';
        minute = (str[3] - '0') * 10;
        minute += str[4] - '0';
        if (minute >= 60)
        {
            minute -= 60;
            hour += 1;
        }
        second = (str[6] - '0') * 10;
        second += str[7] - '0';
        if (second >= 60)
        {
            second -= 60;
            minute += 1;
        }
    }
}

int main()
{
    string str;
    Time t;
    cout << "The initial universal time is ";
    t.printUniversal();
    cout << "\nThe initial standard time is ";
    t.printStandard();

    cout << "\ncurrent time[hour (0~22):minute(0~99):second(0~99)]=";
    getline(cin, str);
    t.printNumber(str);

    cout << "\n\nUniversal time after setTime is ";
    t.printUniversal();
    cout << "\nStandard time after setTime is ";
    t.printStandard();
    cout << endl;
}

