#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void matrix_search(int arr[100][100], int m) {
	int arr2[100][100] = { 0 };
	int indx = m - 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			arr2[i][j] = arr[j][indx];
		}
		--indx;
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << arr2[i][j]<<' ';
		}
		cout << endl;
	}

	cout << endl;
}

int main() {
	int m = 0;
	cin >> m;

	if (m < 1 || m > 1000) {
		return 0;
	}

	int arr[100][100] = { 0 };

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	matrix_search(arr, m);

	return 0;
}
