#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void allindex(int* arr, int size, int target, int i) {
	//base case
	if (i == size) {
		return;
	}

	//recursion case
	if (arr[i] == target) {
		cout << i << ' ';
	}

	allindex(arr, size, target, i + 1);
}

int firstindex(int* arr, int size, int target, int i) {

	//base case
	if (i == size) {
		return -1;
	}

	//recursion case
	if (arr[i] == target) {
		return i;
	}
	else {
		return firstindex(arr, size, target, i + 1);
	}
}

int lastindex(int* arr, int size, int target, int i) {

	//base case
	if (i < 0) {
		return -1;
	}

	//recursion case
	if (arr[i - 1] == target) {
		return i - 1;
	}
	else {
		return lastindex(arr, size, target, i - 1);
	}
}

int main() {
	int size = 0, target = 0;

	cin >> size;

	int* arr{ new int[size] {0} };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	cin >> target;


	// Check for existance and print every index number
	allindex(arr, size, target, 0);
	cout << endl;

	//for first && last index number
	cout << "First index found at " << firstindex(arr, size, target, 0) << endl;
	cout << "Last index found at " << lastindex(arr, size, target, size) << endl;

	return 0;
}
