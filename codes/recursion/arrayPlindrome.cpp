#include <iostream>

bool checkPalindrome(int* arr, int i, int size) {
	// base case
	if (i >= size) {
		return true;
	}

	// recursive case
	if (arr[i] == arr[size]) {
		return checkPalindrome(arr, i + 1, size - 1);
	}

	return false;
}

int main() {
	int size = 0;

	std::cin >> size;

	int* arr{ new int[size] {0} };

	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	if (checkPalindrome(arr, 0, size - 1)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}

	delete[] arr;

	return 0;
}
