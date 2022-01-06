
class MyTest
{
public:
    MyTest()
    {
        cout << "Constructing MyTest object.\n";
    }
    ~MyTest()
    {
        cout << "Destructing MyTest object.\n";
    }
};

int main()
{
    try
    {
        MyTest Demo;
        throw 1;
    }
    catch (int error)
    {
        cout << "Caught: " << error << endl;
    }

    return 0;
}