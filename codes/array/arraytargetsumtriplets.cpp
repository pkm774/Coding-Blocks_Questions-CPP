#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <algorithm>
using std::sort;

void findTargetSum(int* arr, int size, int target) {
	sort(arr, arr + size);

	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			for (int k = j + 1; k < size; ++k) {
				if (arr[i] + arr[j] + arr[k] == target) {
					cout << arr[i] << ", " << arr[j] << " and " << arr[k] << endl;
				}
			}
		}
	}
}

int main() {
	int size = 0;
	int arr[1000] = { 0 };
	int target = 0;

	cin >> size;

	if (size < 1 || size > 1000) {
		return 0;
	}

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	cin >> target;

	findTargetSum(arr, size, target);

	return 0;
}
