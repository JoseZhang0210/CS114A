#include<iostream>
using namespace std;

string DecimalToRoman(int num)
{
    if (num < 0)
        throw 1;
    static const int decimal[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    static const string symbol[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

    for (int i = 0;i < 13;i++)
    {
        if (num / decimal[i])
        {
            num -= decimal[i];
            if (num == 0)
                return symbol[i];
            return (symbol[i] + DecimalToRoman(num));
        }
    }
}

int main()
{
    int number;
    cout << "Input: Integer = ";
    cin >> number;

    try
    {
        cout << "Output: \"" << DecimalToRoman(number) << "\"";
    }
    catch (const int error)
    {
        cout << "Negative and zero are not allowed.\n";
    }

    return 0;
}