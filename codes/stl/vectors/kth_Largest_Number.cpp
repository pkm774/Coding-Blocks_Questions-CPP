#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int size = 0;
	std::cin >> size;

	int k = 0;
	std::cin >> k;

	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	std::sort(arr.begin(),arr.end());

	int pos = size - k;
	std::cout << arr[pos] << std::endl;
}
