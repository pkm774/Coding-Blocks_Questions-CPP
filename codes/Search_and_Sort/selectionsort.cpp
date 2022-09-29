#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

void selectionSort(int* arr, int size) {
	int i = 0, j = 0, small = 0;

	while (i < size - 1) {
		small = i;
		j = i + 1;
		while (j < size) {
			if (arr[j] < arr[small]) {
				small = j;
			}
			++j;
		}
		swap(arr[i], arr[small]);
		++i;
	}

	for (int k = 0; k < size; ++k) {
		cout << arr[k] << endl;
	}
}

int main() {
	int size = 0;

	cin >> size;

	int* arr{ new int[size] { 0 } };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	selectionSort(arr, size);

	delete[] arr;

	return 0;
}
