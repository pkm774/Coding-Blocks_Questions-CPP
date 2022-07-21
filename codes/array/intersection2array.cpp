#include <iostream>

using namespace std;

int main() {
	int arr1[100000] = {};
	int arr2[100000] = {};
	int result[100000] = {};
	int size = 0;

	cin >> size;

	for (int i = 0; i < size; ++i) {
		cin >> arr1[i];
	}

	for (int j = 0; j < size; ++j) {
		cin >> arr2[j];
	}

	for (int k = 0; k < size; ++k) {
		for (int l = 0; l < size; ++l) {
			if (arr1[k] == arr2[l]) {
				result[k] == arr2[l];
			}
		}
	}



	return 0;
}
