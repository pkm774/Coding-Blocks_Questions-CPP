#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void waveRowWise(int arr[10][10], int m, int n) {

	int row = 0;

	while (row < m) {
		if (row % 2 == 0) {
			for (int i = 0; i < n; ++i) {
				cout << arr[row][i] << ", ";
			}
		}
		else {
			for (int i = n - 1; i >= 0; --i) {
				cout << arr[row][i] << ", ";
			}
		}
		++row;
	}
	cout << "END"<<endl;
}

int main() {
	int m = 0, n = 0;
	cin >> m >> n;

	if (m < 1 || m > 10 || n < 1 || n > 10) {
		return 0;
	}

	int arr[10][10] = {0};

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}

	waveRowWise(arr, m, n);

	return 0;
}
