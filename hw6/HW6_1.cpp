#include <iostream>
#include <iomanip>

using namespace std;

//string getASCII(int const ascii)
//{
//
//}

int main()
{
    int start_num, end_num;
    cout << "Please input the range: \n";
    while (cin >> start_num >> end_num)
    {
        if (!(start_num <= end_num || 0 <= start_num || end_num <= 126))
        {
            cout << "numbers should be 0~126, please try again.\n";
            continue;
        }
        cout << "Decimal  Octal  Hexadecimal  Character\n";
        for (int i = start_num;i <= end_num;i++)
        {
            cout.setf(ios::showbase);
            cout << dec << setw(7) << i;
            cout << oct << setw(7) << i;
            cout << hex << setw(13) << i;
            cout << setw(11) << char(i);
            cout << endl;
        }
        cout << "\nPlease input the range: \n";
    }
}
