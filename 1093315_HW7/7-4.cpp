#include <iostream>
using namespace std;

class MyTest
{
public:
    MyTest()
    {
        construct_counter++;
        this_MyTest_number = construct_counter;
        cout << "Constructing object number " << construct_counter << endl;
        if (construct_counter == 5)
        {
            throw 1;
        }
    }
    ~MyTest()
    {
        cout << "Destructing object number " << this_MyTest_number << endl;
    }
private:
    static int construct_counter;
    int this_MyTest_number;
};

int MyTest::construct_counter = 0;

int main()
{
    try
    {
        MyTest array[5];
    }
    catch (int i)
    {
        cout << "Caught: " << i << endl;
    }

    return 0;
}