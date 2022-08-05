#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#include<algorithm>
using std::sort;

int Binary_Search_Iteration(int* arr, int key, int low, int high) {

	while (low <= high) {
    int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
}

int main() {
	int size, low = 0, high, key;

	cin >> size;
	high = size - 1;

	if (size <= 0) {
		return 0;
	}

	int* arr{ new int[size] {0} };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + size);

	cin >> key;

	cout << Binary_Search_Iteration(arr, key, low, high) << endl;

	return 0;
}
