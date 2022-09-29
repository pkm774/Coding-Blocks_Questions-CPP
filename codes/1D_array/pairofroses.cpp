#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


void calcPrice(int numrose, int* price, int amount) {
	int k = 0;
	int l = numrose - 1;
	int min = INT_MAX, ith = 0, jth = 0, difference = 0;

	sort(price, price + numrose);

	while (k < l) {
		if (price[k] + price[l] == amount) {
			difference = price[l] - price[k];
			if (difference <= min) {
				min = difference;
				ith = price[k];
				jth = price[l];
			}
			++k;
			--l;
		}
		else if (price[k] + price[l] < amount) {
			++k;
		}
		else if (price[k] + price[l] > amount) {
			--l;
		}
	}

	cout << "Deepak should buy roses whose prices are " << ith << " and " << jth << "." << endl;
}

int main() {
	int testcase = 0, numrose = 0;
	int price[10000] = {};
	int amount = 0, i = 1;

	cin >> testcase;

	while (i <= testcase) {
		cin >> numrose;

		for (int j = 0; j < numrose; ++j) {
			cin >> price[j];
		}

		cin >> amount;

		calcPrice(numrose, price, amount);

		cout << '\n';
		++i;
	}

	return 0;
}
