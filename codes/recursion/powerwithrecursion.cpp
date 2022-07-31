#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int printPower(int x, int n) {
	//base case
	if (n == 0) {
		return 1;
	}

	//recursion case
	return x * printPower(x, n - 1);
}

int main() {
	int n = 0, x = 0;

	cin >> x >> n;

	cout<<printPower(x, n);

	return 0;
}
