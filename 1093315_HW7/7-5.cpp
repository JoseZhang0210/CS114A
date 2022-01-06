#include <iostream>
#include <cmath>
using namespace std;

const long long Min = -pow(2, 31);
const long long Max = pow(2, 31) - 1;

long long reverse(long long input)
{
    long long ans = 0;
    while (input)
    {
        ans = ans * 10 + input % 10;
        input /= 10;
    }
    return ans;
}


int main()
{
    long long input;
    cout << "Input: x = ";
    cin >> input;
    try 
    {
        if (input<Min || input>Max)
            throw 1;
        cout << "Output: " << reverse(input);
    }
    catch(...)
    {
        cout << "Error!\n";
    }
    return 0;
}