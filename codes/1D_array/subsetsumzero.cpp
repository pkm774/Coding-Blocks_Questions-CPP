#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cmath>
using std::pow;

bool subSet(int* arr, int setSize) {
	int counter = 0, j = 0;

	// Get size for powerset
	// datatype is double to avoid int to double coversion
	double power_set_size = pow(2, setSize);

	// Counter will start from 1
	for (counter = 1; counter < power_set_size; ++counter) {
		int sum = 0;
		for (j = 0; j < setSize; ++j) {
			if (counter & (1 << j)) {
				sum += arr[j];
			}
		}
		if (sum == 0) {
			return true;
		}
	}

	return false;
}

int main() {
	int testCase = 0, setSize = 0;

	cin >> testCase;

	while (testCase > 0) {
		// Input of sets Size
		cin >> setSize;

		// Proceed only for valid input
		if ((setSize < 1) || (setSize > 4)) {
			return 0;
		}

		// Create array with dynamic size
		int* arr{ new int[setSize] {0} };

		// Input of elemets
		for (int i = 0; i < setSize; ++i) {
			cin >> arr[i];
		}

		// Check for for subsets sum
		if(subSet(arr, setSize)){
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}

		// free up array memory
		delete[] arr;

		--testCase;
	}

	return 0;
}
