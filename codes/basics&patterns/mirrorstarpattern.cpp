#include <iostream>

using namespace std;

int main()
{
    int row, i, j, k;
    cin >> row;
    for (i = 1; i <= row; i++)
    {
       if (i % 2 != 0)
        {
            for (j = 1; j <= row - i; j++)
            {
                cout << " ";
            }
            for (k = 1; k <= i; k++)
            {
                cout << "*" << ' ';
            }
            cout << endl;
        }
    }
    for (i = 2; i <= row; i++)
    {
       if (i % 2 != 0)
       {
            for (j = 2; j <= i; j++)
            {
                cout << " ";
            }
            // for (k = 1; k <= (row - i) + 1; k++)
            for (k = 0; k <= row - i; k++)
            {
                cout << "*" << ' ';
            }
            cout << endl;
        }
    }
}