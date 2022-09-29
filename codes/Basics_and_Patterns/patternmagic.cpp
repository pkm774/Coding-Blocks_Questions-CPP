#include <iostream>
using namespace std;
int main()
{
    int row, i, j, k;
    cin >> row;

    for (i = 0; i < row; i++)
    {

        for (j = i; j < row; j++)
        {

            cout << '*';
        }

        for (k = 1; k <= (2 * i) - 1; k++)
        {

            cout << ' ';
        }

        if (i == 0)
        {

            for (j = i; j < row - 1; j++)
            {

                cout << '*';
            }
        }

        else
        {

            for (j = i; j < row; j++)
            {

                cout << '*';
            }
        }

        cout << endl;
    }

    for (i = row - 2; i >= 0; i--)
    {

        for (j = i; j < row; j++)
        {

            cout << '*';
        }

        for (k = 1; k <= (2 * i) - 1; k++)
        {

            cout << ' ';
        }

        if (i == 0)
        {

            for (j = i; j < row - 1; j++)
            {

                cout << '*';
            }
        }

        else
        {

            for (j = i; j < row ; j++)
            {

                cout << '*';
            }
        }

        cout << endl;
    }

    return 0;
}