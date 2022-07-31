#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int add(int *arr, int size) {
	//base case
	if (size == 1) {
		return arr[0];
	}

	//recursion case
	return arr[0] + add(arr + 1, size - 1);
}

int add2(int* arr, int size) {
	//baseA case
	if (size == 1) {
		return arr[0];
	}

	//recursion case
	return arr[size-1] + add2(arr, size - 1);
}

int add3(int* arr, int size, int i) {
	//base case
	if (i == size) {
		return 0;
	}

	//recursion case
	return arr[i] + add3(arr, size, i + 1);
}

int main() {
	int size = 0;

	cin >> size;

	int* arr{ new int[size] {0} };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	cout << add(arr, size) << endl;
	cout << add2(arr, size) << endl;
	cout << add3(arr, size, 0) << endl;

	return 0;
}
