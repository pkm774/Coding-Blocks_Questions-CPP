#include <iostream>

// kth root

long long multiply(long long n, int k) {
	long long ans = 1;
	for (int i = 1; i <= k; ++i) {
		ans = ans * n;
	}

	return ans;
}

void findInt(long long n, int k) {
	long long  low = 0, high = n;
	int x = 0;

	while (low <= high) {
		long long mid = (low + high) / 2;
		if (multiply(mid, k) == n) {
			std::cout << mid << std::endl;
			return;
		}
		if (multiply(mid, k) > n) {
			high = mid - 1;
		}
		if (multiply(mid, k) < n) {
			low = mid + 1;
		}
	}
}

int main() {
	int test = 0, k = 0;
	long long n = 0;

	std::cin >> test;

	while (test--) {
		std::cin >> n >> k;
		findInt(n, k);
	}

	return 0;
}
