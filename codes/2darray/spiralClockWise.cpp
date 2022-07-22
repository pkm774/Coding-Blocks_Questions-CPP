#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void spiralClockWise(int arr[10][10], int m, int n) {



	cout << "END" << endl;
}

int main() {
	int m = 0, n = 0;
	cin >> m >> n;

	if (m < 1 || m > 10 || n < 1 || n > 10) {
		return 0;
	}

	int arr[10][10] = { 0 };

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	spiralClockWise(arr, m, n);

	return 0;
}
