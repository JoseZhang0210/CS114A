#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include "1093315_goal01.h"
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



int main()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);

    Time t;
    cout << "The initial universal time is ";
    t.printUniversal();
    cout << "\n The initial standard time is ";
    t.printStandard();

    t.setTime(ltm->tm_hour,ltm->tm_min,ltm->tm_sec);

    cout << "\n\nUniversal time after setTime is ";
    t.printUniversal();
    cout << "\nStandard time after setTime is ";
    t.printStandard();
}

