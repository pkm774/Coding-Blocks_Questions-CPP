#include <iostream>

using namespace std;

void findWater(int* arr, int size) {
	int left[10000] = { 0 };
	int right[10000] = { 0 };
	int ans = 0;

	left[0] = arr[0];
	right[size - 1] = arr[size - 1];

	for (int k = 1; k < size; ++k) {
		left[k] = max(left[k - 1], arr[k]);
	}

	for (int l = size - 2; l >= 0; --l) {
		right[l] = max(right[l + 1], arr[l]);
	}

	for (int m = 0; m < size; ++m) {
		ans = ans + min(left[m], right[m]) - arr[m];
	}

	cout << ans << endl;
}

int main() {
	int testcase = 0;
	int max = 0;
	int arr[10000] = { 0 };

	cin >> testcase;

	for (int i = 1; i <= testcase; ++i) {

		cin >> max;

		for (int j = 0; j < max; ++j) {
			cin >> arr[j];
		}

		findWater(arr, max);
	}

	return 0;
}
