#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::string;

void form_biggest_number()
{
    int total = 0;

    cin >> total;

    string* arr{ new string[total] {""} };

    for (int i = 0; i < total; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (arr[i] + arr[j] < arr[j] + arr[i])
            {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    string rets = "";
    for (int i = 0; i < total; i++) {
        rets += arr[i];
    }

    cout << rets << endl;

    delete[] arr;
}

int main()
{
    long long test = 0;

    cin >> test;

    while (test--)
    {
        form_biggest_number();
    }

    return 0;
}
