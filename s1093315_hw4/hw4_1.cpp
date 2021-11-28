#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string strToInt(string str)
{
    int num = 0, sum = 0;
    bool noneFlag = 1;//if there is no digit, it remains true.
    
    for (int i = 0; i < size(str); i++)
    {
        if (isdigit(str[i]))
        {
            noneFlag = 0;
            num *= 10;
            num += str[i] - '0';
        }
        else
        {
            sum += num;
            num = 0;
        }
    }
    if (num)
    {
        sum += num;
        num = 0;
    }
    
    return noneFlag ? "None" : to_string(sum);
}

int main()
{
    stringstream results;
    string input, output;

    cout << "Welcome to input\n";
    while (getline(cin, input) && !input.empty())
    {
        results << strToInt(input) << ' ';
    }
    
    while (results >> output)
    {
        cout << output << '\n';
    }

    return 0;
}

