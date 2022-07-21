#include <iostream>

using namespace std;

int main() {
	int low, high;
	int max = 0;
	cin >> low >> high;

	for (int i = low; i <= high; ++i) {
		int num1 = i;
		int num2 = i + 1;

		int checkxor = num1 ^ num2;
		if (checkxor > max) {
			max = checkxor;
		}
	}

	cout << max;
	return 0;
}
