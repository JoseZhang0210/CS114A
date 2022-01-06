#include <iostream>
using namespace std;

class MyTest
{
public:
    MyTest()
    {
        cout << "Constructing MyTest Object." << endl;
    }
    ~MyTest()
    {
        cout << "Destructing MyTest Object." << endl;
    }
};

class MyTestWithError
{
public:
    MyTestWithError()
    {
        cout << "Constructing MyTestWithError Object." << endl;
        throw 1;
    }
    ~MyTestWithError()
    {
        cout << "Destructing MyTestWithError Object." << endl;
    }
};

int main()
{
    try
    {
        MyTest demo1;
        MyTestWithError demo2;
        MyTest demo3;
    }
    catch (int i)
    {
        cout << "Caught: " << i << endl;
    }
}