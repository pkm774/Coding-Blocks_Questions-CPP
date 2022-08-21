#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a = n, diff = 0, mask = 0;
    int indx = 0;

    while (n != 0)
    {
        n = n >> 1;
        indx++;
    }
    n = a;

    while (indx--)
    {
        mask = (long long)1 << indx;
        n = n | mask;
    }

    diff = n - a;

    cout << diff << " " << n;

    return 0;
}