#include <iostream>

using namespace std;

int main()
{
    int row, i, j, a = 0, b = 1, c = 0;
    /* Enter number of rows */
    cin >> row;

    /* Loop to check rows */
    for (i = 0; i < row; i++)
    {
        int counter = 0;
        /* loop for coloumns */
        for (j = 0; j <= i; j++)
        {
            while (counter <= i)
            {
                cout << c << ' ';
                a = b;
                b = c;
                c = a + b;
                counter += 1;
            }
        }
        cout << endl;
    }
    return 0;
}