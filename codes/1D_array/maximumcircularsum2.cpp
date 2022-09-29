#include <iostream>

using namespace std;

int main()
{
    int arr[100000], n, t, sum;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int tsum = 0, mx = 0, mn = 0, s = INT_MIN, d = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            tsum = tsum + arr[i]; // total sum
        }
        for (int i = 0; i < n; i++)
        {
            mx = mx + arr[i];
            s = max(s, mx); // max sum using kadanes
            if (mx < 0)
            {
                mx = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            mn = mn + arr[i];
            d = min(d, mn); // min sum using kadanes
            if (mn > 0)
            {
                mn = 0;
            }
        }
        sum = tsum - d;
        if (sum > s)
        {
            cout << sum << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}