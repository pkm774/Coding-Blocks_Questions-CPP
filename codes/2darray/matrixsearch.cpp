#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool matrix_search(int arr[10][10], int m, int n, int key) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == key) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int m = 0, n = 0;
	int key = 0;
	cin >> m >> n;

	if (m < 1 || m > 30 || n < 1 || n > 30) {
		return 0;
	}

	int arr[10][10] = { 0 };

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	cin >> key;

	if (matrix_search(arr, m, n, key)) {
		cout << '1' << endl;
	}
	else {
		cout << '0' << endl;
	}

	return 0;
}
