#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        for (int j = 2 * i; j <= n; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << i - j + 1 << " ";
        }
        for (int j = 2; j <= i; j++)
        {
            cout << "  ";
        }
        for (int j = 2; j < i; j++)
        {
            cout << "  ";
        }
        if (i > 1)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    for (int i = n / 2; i >= 1; i--)
    {
        for (int j = 2 * i; j <= n; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << i - j + 1 << " ";
        }
        for (int j = 2; j <= i; j++)
        {
            cout << "  ";
        }
        for (int j = 2; j < i; j++)
        {
            cout << "  ";
        }
        if (i > 1)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}