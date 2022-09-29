#include <iostream>

using namespace std;

int main()
{
    int num, i, j;
    cin >> num;
    for (i = 0; i < num; i++)
    {
        int val = 1;
        for (j = 0; j <= i; j++)
        {
            cout << val << ' ';
            val = val * (i - j) / (j + 1);
        }
        cout << endl;
    }
    return 0;
}