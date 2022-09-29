#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void deleteElement(int* arr, int size) {
	cout << "Enter element to be deleted: ";
	int element;
	cin >> element;

	for (int i = 0; i < size; ++i) {
		if (arr[i] == element) {
			--size;
			for (int j = i; j < size; ++j) {
				arr[j] = arr[j + 1];
			}
		}
	}

	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
}

void deleteAll_equalElement(int* arr, int size) {
	cout << "Enter element to be deleted with duplicacy: ";
	int element;
	cin >> element;

	for (int i = 0; i < size; ++i) {
		if (arr[i] == element) {
			--size;
			for (int j = i; j < size; ++j) {
				arr[j] = arr[j + 1];
			}
			--i;
		}
	}

	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
}

int main() {
	int size = 0;

	cout << "Enter total size of array: ";
	cin >> size;

	int* arr{ new int [size] {0} };

	cout<<"Enter elements of array: ";
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	deleteElement(arr, size);
	deleteAll_equalElement(arr, size;

	delete[] arr;

	return 0;
}
