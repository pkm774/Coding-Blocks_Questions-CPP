#include <iostream>

using namespace std;

int main()
{
    int row, i, j;
    cin >> row;
    for (i = 1; i <= row; i++)
    {
        int start;
        if (i % 2 == 0)
        {
            start = 0;
        }
        else
        {
            start = 1;
        }
        for (j = 1; j <= i; j++)
        {
            cout << start << ' ';
            if (start == 0)
            {
                start = 1;
            }
            else
            {
                start = 0;
            }
        }
        cout << endl;
    }
    return 0;
}