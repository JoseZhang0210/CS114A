#include <iostream>
#include <string>

using namespace std;

#define print_arr_int for (int i=0;i<element_amount[0];i++)cout << *(int_arr + i) << " ";\
cout << endl;
#define print_arr_double for (int i=0;i<element_amount[1];i++)cout << *(double_arr + i) << " ";\
cout << endl;
#define print_arr_float for (int i=0;i<element_amount[2];i++)cout << *(float_arr + i) << " ";\
cout << endl;

template <typename T> void sorting(T* arr_begin, T* arr_end)
{
    for(int sort_point=0;arr_begin+ sort_point <arr_end;sort_point++)
        for (int search_point = sort_point + 1;arr_begin + search_point < arr_end;search_point++)
        {
            if (*(arr_begin + sort_point) < *(arr_begin + search_point))
            {
                *(arr_begin + sort_point) += *(arr_begin + search_point);
                *(arr_begin + search_point) = *(arr_begin + sort_point) - *(arr_begin + search_point);
                *(arr_begin + sort_point) -= *(arr_begin + search_point);
            }
        }
}

template <typename T> void inverting(T* arr_begin, T* arr_end)
{
    arr_end -= 1;
    if (arr_begin == arr_end || arr_begin + 1 == arr_end);
    else
    {
        while (arr_begin != arr_end || arr_begin + 1 != arr_end)
        {
            *arr_begin += *arr_end;
            *arr_end = *arr_begin - *arr_end;
            *arr_begin -= *arr_end;
            arr_begin++;
            if (arr_begin == arr_end)
                break;
            arr_end--;
            if (arr_begin == arr_end)
                break;
        }
    }
}

template <typename T, typename target_T> int searching(T* arr_begin, T* arr_end, target_T target)
{
    for (int i = 0;arr_begin + i != arr_end;i++)
    {
        if (*(arr_begin + i) == target)
        {
            return i;
        }
    }
    return -1;
}

template <typename T> T summing(T* arr_begin, T* arr_end)
{
    T sum = 0;
    for (auto i = arr_begin;i != arr_end;i++)
        sum =sum+ *i;
    return sum;
}

int main()
{
    string input;
    
    cout << "請輸入元素個數:\n";
    while (getline(cin, input))
    {
        int element_amount[3] = { 0 };
        int iter_element_amount = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                element_amount[iter_element_amount] *= 10;
                element_amount[iter_element_amount] += input[i] - '0';
            }
            else iter_element_amount++;
        }
        int* int_arr = new int[element_amount[0]];
        double* double_arr = new double[element_amount[1]];
        float* float_arr = new float[element_amount[2]];


        //input int array
        if (element_amount[0] != 0)
        {
            cout << "請輸入int型態組元素\n";
            for (int i = 0; i < element_amount[0]; i++)
            {
                int input_int = 0;
                cin >> input_int;
                int_arr[i] = input_int;
            } 
        }
        
        //input double array
        if (element_amount[1] != 0)
        {
            cout << "請輸入double型態組元素\n";
            for (int i = 0; i < element_amount[1]; i++)
            {
                double input_double = 0;
                cin >> input_double;
                double_arr[i] = input_double;
            }
        }

        //input float array
        if (element_amount[2] != 0)
        {
            cout << "請輸入float型態組元素\n";
            for (int i = 0; i < element_amount[2]; i++)
            {
                float input_float = 0;
                cin >> input_float;
                float_arr[i] = input_float;
            }
        }

        //process int array
        if (element_amount[0] != 0)
        {
            cout << "Array構造函數:\n";
            print_arr_int;

            sorting(int_arr, int_arr + element_amount[0]);
            cout << "int 型數組:\n排序:\n";
            print_arr_int;
            
            inverting(int_arr, int_arr + element_amount[0]);
            cout << "倒置:\n";
            print_arr_int;

            cout << "請輸入要查找的元素: ";
            int input_int = 0;
            cin >> input_int;
            if (searching(int_arr, int_arr + element_amount[0], input_int) != -1)
                cout << "是第" << searching(int_arr, int_arr + element_amount[0], input_int) + 1 << "個元素" << endl;
            else
                cout << "未找到該元素\n";

            cout << "求和\n數組和為:" << summing(int_arr, int_arr + element_amount[0]) << endl;
        }
        //process double array
        if (element_amount[1] != 0)
        {
            cout << "Array構造函數:\n";
            print_arr_double;

            sorting(double_arr, double_arr + element_amount[1]);
            cout << "double 型數組:\n排序:\n";
            print_arr_double;

            inverting(double_arr, double_arr + element_amount[1]);
            cout << "倒置:\n";
            print_arr_double;

            cout << "請輸入要查找的元素: ";
            double input_double = 0;
            cin >> input_double;
            if (searching(double_arr, double_arr + element_amount[1], input_double) != -1)
                cout << "是第" << searching(double_arr, double_arr + element_amount[1], input_double) + 1 << "個元素" << endl;
            else
                cout << "未找到該元素\n";

            cout << "求和\n數組和為:" << summing(double_arr, double_arr + element_amount[1]) << endl;
        }

        //process float array
        if (element_amount[2] != 0)
        {
            cout << "Array構造函數:\n";
            print_arr_float;

            sorting(float_arr, float_arr + element_amount[2]);
            cout << "float 型數組:\n排序:\n";
            print_arr_float;

            inverting(float_arr, float_arr + element_amount[2]);
            cout << "倒置:\n";
            print_arr_float;

            cout << "請輸入要查找的元素: ";
            float input_float = 0;
            cin >> input_float;
            if (searching(float_arr, float_arr + element_amount[2], input_float) != -1)
                cout << "是第" << searching(float_arr, float_arr + element_amount[2], input_float) + 1 << "個元素" << endl;
            else
                cout << "未找到該元素\n";

            cout << "求和\n數組和為:" << summing(float_arr, float_arr + element_amount[2]) << endl;
        }
        
        //prepare for next case
        string clear_str="";
        getline(cin, clear_str);
        cout << "\n請輸入元素個數:" << endl;
    }
}