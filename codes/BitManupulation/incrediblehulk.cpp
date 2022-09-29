#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int hulk(unsigned int n);

int main() {
	int testCase = 0, n = 0;

	cin >> testCase;

	while (testCase > 0) {
		cin >> n;
		cout << hulk(n) << endl;

		--testCase;
	}

	return 0;
}

int hulk(unsigned int n) {
	int cnt = 0;

	// Till N becomes 0
	while (n) {

		// Removes the set bits from
		// the right to left
		n = n & (n - 1);
		cnt++;
	}

	return cnt;
}
