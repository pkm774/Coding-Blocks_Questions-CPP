#include <iostream>

using namespace std;

int* mergearray(int* arr1, int* arr2, int size) {
	int i = size - 1;
	int j = size - 1;
	int k = (size + size) - 1;

	// loop
	while (i >= 0 && j >= 0) {
		if (arr1[i] > arr2[j]) {
			arr1[k] = arr1[i];
			k--;
			i--;
		}
		else {
			arr1[k] = arr2[j];
			j--;
			k--;
		}
	}

	// loop
	while (j >= 0) {
		arr1[k] = arr2[j];
		k--;
		j--;
	}

	return arr1;
}

int getMedian(int* iarray, int size) {
	int medval = iarray[size - 1];

	return medval;
}

int main() {
	int max = 0, medianval;
	int arr1[100000] = {}, arr2[100000] = {};
	int* retarr = NULL;

	cin >> max;

	for (int i = 0; i < max; ++i) {
		cin >> arr1[i];
	}

	for (int j = 0; j < max; ++j) {
		cin >> arr2[j];
	}

	retarr = mergearray(arr1, arr2, max);

	medianval = getMedian(retarr, max);

	cout << medianval << endl;

	return 0;
}
