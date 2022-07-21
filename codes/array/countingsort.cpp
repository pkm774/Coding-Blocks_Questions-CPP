#include <iostream>

using namespace std;

void countSort(int* arr, int size) {
	// store the maximum value;
	int max = arr[0];
	for (int j = 1; j < size; ++j) {
		if (arr[j] > max) {
			max = arr[j];
		}
	}

	// Create dynamic array with max size and initialize with 0;
	// the size of the array will be max + 1;
	// ex : if max=8 then size = 9; i.e, array from 0 to 8, therefore size = 9;
	int* arr2{ new int[max + 1] { 0 } };

	// Loop for Counting element occurence;
	for (int j = 0; j < size; ++j) {
		arr2[arr[j]]++;
	}

	// Loop for saving elements in new array;
	int* newarr{ new int[size] {0} };
	int indx = 0;
	for (int i = 0; i < max + 1; ++i) {
		if (arr2[i] > 0) {
			for (int j = 1; j <= arr2[i]; ++j) {
				newarr[indx] = i;
				++indx;
			}
		}
	}

	for (int i = 0; i < size; ++i) {
		cout << newarr[i] << ' ';
	}

	delete[] newarr;
	delete[] arr2;
}

int main() {
	int size = 0;

	cin >> size;

	int* arr{ new int[size] {0} };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	countSort(arr, size);

	delete[] arr;

	return 0;
}
