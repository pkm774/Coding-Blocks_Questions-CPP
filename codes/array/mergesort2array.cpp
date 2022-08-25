#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<algorithm>
using std::sort;

void mergeSort(int* arr1, int* arr2, int size1, int size2) {
	int i = 0, j = 0, k = 0;

	int size3 = size1 + size2;

	int* arr3{ new int [size3] {0} };

	while (i < size1 && j < size2) {
		if (arr1[i] <= arr2[j]) {
			arr3[k++] = arr1[i++];
		}
		else {
			arr3[k++] = arr2[j++];
		}
	}

	while (i < size1) {
		arr3[k++] = arr1[i++];
	}

	while (j < size2) {
		arr3[k++] = arr2[j++];
	}

	for (int k = 0; k < size3; ++k) {
		cout << arr3[k] << ' ';
	}

	delete[] arr3;
}

int main() {
	int size1 = 0;

	cin >> size1;

	if (size1 < 0) {
		return 0;
	}

	int* arr1{ new int [size1] {' '} };

	for (int i = 0; i < size1; ++i) {
		cin >> arr1[i];
	}

	sort(arr1, arr1 + size1);

	int size2 = 0;

	cin >> size2;

	if (size2 < 0) {
		return 0;
	}

	int* arr2{ new int [size2] {' '} };

	for (int i = 0; i < size2; ++i) {
		cin >> arr2[i];
	}

	sort(arr2, arr2 + size2);

	mergeSort(arr1, arr2, size1, size2);

	delete[] arr1,arr2;

	return 0;
}
