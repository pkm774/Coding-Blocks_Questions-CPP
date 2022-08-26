#include <iostream>

// print prime numbers upto 50;
void primeSeive(int n) {
	int arr[51] = { 0 };

	for (int i = 2; i <= n; ++i) {
		if (arr[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				if (j % i == 0) {
					arr[j] = 1;
				}
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		if (arr[i] != 1) {
			std::cout << i << ' ';
		}
	}

	std::cout << std::endl;
}

int main() {
	int num = 0;
	std::cin >> num;

	if (num > 50 || num < 0)
		return 0;

	primeSeive(num);

	return 0;
}
