#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Checking form first index
// Forward Direction or Acending order
// Index are modified
bool checkSorted_1(int* arr, int size) {

	//base case
	if (size == 1) {
		return true;
	}

	//recursion case
	if (arr[0] <= arr[1] && checkSorted_1(arr + 1, size - 1)) {
		return true;
	}

	return false;
}

// Checking from last lastindex
// Backward Direction or Decending Order
// Index are modified
bool checkSorted_2(int* arr, int size) {

	//base case
	if (size == 1) {
		return true;
	}

	//recursion case
	if (arr[size - 2] <= arr[size - 1] && checkSorted_2(arr, size-1)) {
		return true;
	}

	return false;
}

// Checking in acending order but without modifing index
// Variable i will start from first index i.e, 0
int checkSorted_3(int* arr, int size, int i) {

	//base case
	if (i == size - 1) {
		return true;
	}

	//recursion case
	if (arr[i] <= arr[i + 1] && checkSorted_3(arr, size, i + 1)) {
		return true;
	}

	return false;
}

int main() {
	int size = 0;

	cin >> size;

	int* arr{ new int[size] {0} };

	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	if(checkSorted_3(arr, size, 0)){
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	delete[] arr;

	return 0;
}
