#include <iostream>
#include <algorithm>

using namespace std;


void checkArray(int* arr1, int* arr2, int size) {

	int number = 0, size2 = 0, i = 0, j = 0, k = 0;
	int arr3[1000] = {};

	while (i < size && j < size) {
		if ((arr1[i] == number) && (arr2[j] == number)) {
			arr3[k] = number;
			++k;
			++size2;
			++i;
			++j;
		}
		else if ((arr1[i] != number) || (arr2[j] != number)) {
			if (arr1[i] < arr2[j]) {
				++i;
				++number;
			}
			else if (arr1[i] > arr2[j]) {
				++j;
				++number;
			}
			else {
				++number;
			}
		}
	}

	cout << '[';
	for (int m = 0; m < size2; ++m) {
		cout << arr3[m];
		if(m != size2 - 1) {
			cout << ", ";
		}
	}
	cout << ']' << endl;
}

int main() {
	int arr1[100] = { 0 };
	int arr2[100] = { 0 };
	int max = 0;

	cin >> max;

	for (int i = 0; i < max; ++i) {
		cin >> arr1[i];
	}

	for (int j = 0; j < max; ++j) {
		cin >> arr2[j];
	}

	sort(arr1, arr1 + max);
	sort(arr2, arr2 + max);

	checkArray(arr1, arr2, max);

	return 0;
}
