#include <iostream>

int nthTriangle(int n) {
	// base case
	if (n == 0) {
		return 0;
	}

	// recursive case
	return n + nthTriangle(n - 1);
}

int main() {
	int num = 0;

	std::cin >> num;

	std::cout << nthTriangle(num) << std::endl;

	return 0;
}
