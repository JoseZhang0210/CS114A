#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool CanTransform(const string start, const string end)
{
    int Rs = 0, Re = 0, Ls = 0, Le = 0;
    //Length check
    if (start.length() != end.length())
        return false;

    //Checking 'R' from left to right
    for (int i = 0;i < start.length();i++)
    {
        if (start[i] == 'R')
            Rs++;
        if (end[i] == 'R')
            Re++;
        if (Rs < Re)
            return false;
    }

    //Checking 'L' from right tp left
    for (int i = start.length() - 1;i >= 0;i--)
    {
        if (start[i] == 'L')
            Ls++;
        if (end[i] == 'L')
            Le++;
        if (Ls < Le)
            return false;
    }

    return (Rs == Re && Ls == Le) ? true : false;
}

void Explanation(string start, const string end)
{
    cout << "Explanation:\n"
        << "We can transform start to end following these steps:\n";
    cout << start;
    cout << ((start == end) ? "\n" : " ->\n");

    for (int i = 0; i < start.length();i++)
    {
        if (start[i] == end[i])continue;
        if (start[i] == 'R')
        {
            for (int j = start.find('X', i);j > i;j--)
            {
                swap(start[j], start[j - 1]);
                cout << start;
                cout << ((start == end) ? "\n" : " ->\n");
            }
        }
        else//start[i]=='X', end[i+?]=='L'
        {
            for (int j = start.find('L', i);j > i;j--)
            {
                swap(start[j], start[j - 1]);
                cout << start;
                cout << ((start == end) ? "\n" : " ->\n");
            }

        }
    }
}

int main()
{
    string start, end;

    while (cin >> start >> end)
    {
        cout << "Input: start = \"" << start << "\", end = \"" << end << "\"\n";
        if (CanTransform(start, end))
        {
            cout << "Output: True\n";
            Explanation(start, end);
        }
        else
            cout << "Output: False\n";
    }

    return 0;
}