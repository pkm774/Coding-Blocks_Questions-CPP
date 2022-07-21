#include<iostream>

using namespace std;

int main() {
	int size = 0, arr[100];
	int i, j;

	cin >> size;

	for (i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	for (j = 0; j < size; ++j) {
		if (arr[j] == 0) {
			arr[0] = 0;
		}
		else {
			arr[size - j] = arr[j];
		}
	}

	for (i = 0; i < size; ++i) {
		cout << arr[i];
	}

	return 0;
}
