#include <iostream>

using namespace std;

void checkPhone(int m, int n) {
	int i = 1;
	int j = 0, k = 0;

	while (j <= m || k <= n) {
		if (i & 1) {
			j = j + i;
		}
		else {
			k = k + i;
		}
		++i;
	}

	if (j > k) {
		cout << "Aayush" << endl;
	}
	else {
		cout << "Harshit" << endl;
	}
}

int main() {
	int testcase = 0, count = 1;
	int m = 0, n = 0;

	cin >> testcase;

	while (count <= testcase) {
		cin >> m >> n;

		checkPhone(m, n);

		++count;
	}
}
