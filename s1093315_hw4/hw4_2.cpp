#include <iostream>

using namespace std;

int main()
{
    string input;
    cout << "Welcome to input\n";
    cin >> input;

    //print pyramid
    int i = 0, inputLength = size(input);

    for (int row = 0;row < (inputLength / 2) + 1;row++)
    {
        i = row;
        cout << '\n';
        
        //space
        for (int j = (inputLength / 2);j > row;j--)
        {
            cout << ' ';
        }
        
        //left
        for (int j = 0;j < row;j++)
        {
            cout << input[i];
            i++;
        }
        
        //mid
        cout << input[i];
        i--;
        
        //right
        for (int j = 0;j < row;j++)
        {
            cout << input[i];
            i--;
        }
    }

    return 0;
}