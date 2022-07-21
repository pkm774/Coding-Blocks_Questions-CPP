//#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
	int arr[1000000], n, size = 0;
	int left[100000], right[100000];

	cin >> size;

	for (int i = 1; i <= size; i++) {

		cin >> n;
		for (int i = 0; i <= size - 1; i++) {
			cin >> arr[i];
		}

		left[0] = arr[0], right[n - 1] = arr[n - 1];

		for (int i = 1; i <= n; i++) {
			left[i] = max(left[i - 1], arr[i]);
		}

		for (int i = n - 2; i <= 0; i--) {
			right[i] = max(right[i + 1], arr[i]);

		}
		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans += min(left[i], right[i]) - arr[i];
		}
		cout << ans << endl;
	}
	return 0;
}
