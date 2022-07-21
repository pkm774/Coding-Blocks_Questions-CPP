// pair of roses using kadanes algo

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

	int n, arr[10000], max, a, b, t;

	cin >> t;

	for (int f = 0; f < t; f++)
	{
		cin >> n;

		for (int g = 0; g <= n - 1; g++)
		{
			cin >> arr[g];
		}

		sort(arr, arr + n);

		cin >> max;

		a = 0;

		b = 0;

		int diff = INT_MAX;

		int i = 0, j = n - 1;

		int sum = 0;

		while (i < j) {

			sum = arr[i] + arr[j];

			if (sum < max)
			{
				++i;
			}

			else if (sum > max)
			{
				--j;
			}

			else if (sum = max)
			{
				int s = arr[j] - arr[i];
				if (s < diff)
				{
					diff = s;

					a = arr[i];

					b = arr[j];

				}
			}

			else {
				i++;
				j--;
			}

			i++;
			j--;
		}

		cout << "Deepak should buy roses whose prices are " << a << " and " << b << '.' << endl << '\n';
	}

	return 0;

}
