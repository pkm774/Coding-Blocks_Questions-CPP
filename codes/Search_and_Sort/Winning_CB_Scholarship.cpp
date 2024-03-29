#include<iostream>
using namespace std;
int main()
{
	// Input N M X Y
	long long n, m, x, y;
	cin >> n >> m >> x >> y;

	// Implement binary search
	long long s = 0;
	long long e = n;
	long long  ans = -1;
	while (s <= e)
	{
		long long mid = (s + e) / 2;
		long long a = (mid * x);
		long long b = m + ((n - mid) * y);
		if (a <= b)
		{
			ans = mid;
			s = mid + 1;
		}
		else if (a == b)
		{
			ans = mid;
			break;
		}
		else
		{
			e = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
