#include <iostream>

int main() {
	int size = 0, target = 0, temp = 0;

	bool found = false;

	std::cin >> size;

	int* arr{ new int [size] {0} };

	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	std::cin >> target;

	for (int i = 0; i < size; ++i) {
		if (arr[i] == target) {
			std::cout << i;
			found = true;
			break;
		}
	}

	if (!found) {
		std::cout << -1;
	}

	std::cout << std::endl;

	delete[] arr;

	return 0;
}
