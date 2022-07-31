#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// From left
bool checksorted(int* arr, int size) {
	//base case
	if (size == 1) {
		return true;
	}

	//recursion case
	if (arr[0] <= arr[1] && checksorted(arr + 1, size - 1)) {
		return true;
	}

	return false;
}


// From right
bool checksorted2(int* arr, int size) {
	//base case
	if (size == 1) {
		return true;
	}

	//recursion case
	if (arr[size - 2] <= arr[size - 1] && checksorted2(arr, size - 1)) {
		return true;
	};

	return false;
}

// Checking by increasing index
bool checksorted3(int* arr, int size, int i) {
	//base case
	if (i == size - 1) {
		return 1;
	}

	//recursion case
	if (arr[i] <= arr[i + 1] && checksorted3(arr, size, i + 1)) {
		return true;
	};

	return false;
}

int main() {
	int size = 0;

	cin >> size;

	int* arr{ new int[size] {0} };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	if (checksorted3(arr, size, 0)) {
		cout << "Sorted" << endl;
	}
	else {
		cout << "Unsorted" << endl;
	}

	return 0;
}
