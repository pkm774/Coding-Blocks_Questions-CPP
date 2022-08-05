#include <iostream>

using std::cout;
using std::cin;
using std::endl;



void InsertionSort(int* arr, int size) {
	int sorted = 0, i = 1;

	while (i < size) {
		int temp = 0;
		if (arr[sorted] <= arr[i]) {
			++sorted;
			++i;
		}
		else {
			temp = arr[sorted];
			arr[sorted] = arr[i];
			arr[i] = temp;
			sorted = 0;
			i = 1;
		}
	}

	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}

	cout << endl;
}

int main() {
	int size = 0;

	cin >> size;

	if (size < 0) {
		return 0;
	}

	int* arr{ new int [size] {0} };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	InsertionSort(arr, size);

	delete[] arr;

	return 0;
}
