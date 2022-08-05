#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#include<algorithm>
using std::sort;

int Binary_Search_Recursion(int* arr, int key, int low, int high) {

	if (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			return Binary_Search_Recursion(arr, key, low, mid - 1);
		}
		else {
			return Binary_Search_Recursion(arr, key, mid + 1, high);
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

	cout << Binary_Search_Recursion(arr, key, low, high) << endl;

	delete[] arr;

	return 0;
}
