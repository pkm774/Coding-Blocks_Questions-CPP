#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

int checkSwaps(long int* arr, long int size) {
	int i = 0;
	int j = size - 1;
	int count = 0;

	while (i < j) {
		if (arr[i] < arr[j]) {
			++i;
		}
		else if (arr[i] == arr[j]) {
			++i;
		}
		else {
			swap(arr[i], arr[j]);
			++count;
			if (i == j - 1) {
				i = 0;
				--j;
			}
			else {
				++i;
				--j;
			}
		}
		if (i == j) {
			i = 0;
			if (arr[i] > arr[j]) {
				j = j;
			}
			else {
				--j;
			}
		}
	}

	return count;
}

int main() {
	long int size = 0;

	cin >> size;

	long int* arr{ new long int[size] { 0 } };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	cout << checkSwaps(arr, size) << endl;

	delete[] arr;

	return 0;
}
