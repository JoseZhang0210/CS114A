#include <iostream>

using namespace std;

bool CanTransform(const string start,const string end)
{
    int Rs = 0, Re = 0, Ls = 0, Le = 0;
    //Length check
    if (size(start) != size(end))
        return false;
    
    //Checking 'R' from left to right
    for (int i = 0;i < size(start);i++)
    {
        if (start[i] == 'R')
            Rs++;
        if (end[i] == 'R')
            Re++;
        if (Rs < Re)
            return false;
    }

    //Checking 'L' from right tp left
    for (int i = size(start) - 1;i >= 0;i--)
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

void Explanation(string start,const string end)
{
    cout<<"Explanation:\n"
        << "We can transform start to end following these steps:\n";
    cout << start;
    if (start != end)
        cout << " ->\n";
    for (int i = 0; i < size(start);i++)
    {
        if (start[i] == end[i])continue;
        if (start[i] == 'R')
        {
            swap(start[i], start[i + 1]);
            cout << start;
            if (start != end)
                cout << " ->\n";
        }
        else//start[i]=='X', end[i+?]=='L'
        {
            for (int j = start.find('L', i);j > i;j--)
            {
                swap(start[j], start[j - 1]);
                cout << start;
                if (start != end)
                    cout << " ->\n";
            }

        }
    }
}

int main()
{
    string start, end;
    cin >> start >> end;

    cout << "Input: start = \"" << start << "\", end = \"" << end << "\"\n";
    if (CanTransform(start, end))
    {
        cout << "Output: True\n";
        Explanation(start, end);
    }
    else
        cout << "Output: False\n";

    return 0;
}