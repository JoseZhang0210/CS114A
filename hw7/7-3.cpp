#include <iostream>
using namespace std;

void ThrowMultipleError(int num)
{
    throw num;
}

void ThrowMultipleError(double num)
{
    throw num;
}

int main()
{

    try
    {
        cout << "\nThrowing int error.\n";
        ThrowMultipleError(1);
    }
    catch (int error)
    {
        cout << "Caught int error: " << error << endl;
    }
    catch (...)
    {
        cout << "Caught non-int error.\n";
    }

    try
    {
        cout << "\nThrowing double error.\n";
        ThrowMultipleError(1.5);
    }
    catch (int error)
    {
        cout << "Caught int error: " << error << endl;
    }
    catch (...)
    {
        cout << "Caught non-int error.\n";
    }

    return 0;
}