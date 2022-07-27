#include <iostream>
using namespace std;

void checkVolume(int n1, int n2) {
	if (n1 > n2) {
		cout << n1 - n2 << endl;
	}
	else if (n2 > n1) {
		cout << n2 - n1 << endl;
	}
	else {
		cout << '0' << endl;
	}
}

int main() {
	int test = 0, x = 0, y = 0;

	cin >> test;

	while (test--) {
		cin >> x >> y;
		checkVolume(x, y);
	}

	return 0;
}
