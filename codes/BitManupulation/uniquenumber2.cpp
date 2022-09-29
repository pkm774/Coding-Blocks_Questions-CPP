#include <iostream>

using namespace std;

int main() {
	int arr[100000] = {};
	int max = 0, xorval = 0;
	int pos = 0, bit = 0;
	int ans[2] = {0};

	cin >> max;

	for (int i = 0; i < max; ++i) {
		cin >> arr[i];
	}

	for (int j = 0; j < max; ++j) {
		xorval ^= arr[j];
	}

	for (int k = 0; k < max; ++k) {
		bit = xorval & (1 << k);
		if (bit != 0) {
			pos = k;
			break;
		}
	}

	for (int k = 0; k < max; ++k) {
		if ((arr[k] & (1 << pos)) > 0) {
			ans[1] ^= arr[k];
		}
		else {
			ans[0] ^= arr[k];
		}
	}

	if(ans[0] > ans[1]){
		cout << ans[1] << " " << ans[0] << endl;
	}
	else {
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}
