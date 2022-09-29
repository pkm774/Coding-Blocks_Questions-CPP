#include <iostream>

using namespace std;

int main()
{
    int row, i, j, k;
    cin >> row;

    for (i = 1; i <= row; i++)
    {
        cout << i << ' ';
        for (j = 3; j <= i; j++)
        {
            cout << '0' <<' ';
        }
        if(i>=2){
            cout<<i;
        }
        cout << endl;
    }
    return 0;
}