#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void matrixTranspose(int arr[100][100], int m) {

	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < m; ++i) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
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

	matrixTranspose(arr, m);

	return 0;
}
