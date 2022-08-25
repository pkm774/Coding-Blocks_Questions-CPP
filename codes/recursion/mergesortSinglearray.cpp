#include <iostream>
#include <vector>

// elements =
//           0 1 | 2 | 3 4
//           4 5 | 3 | 1 2
// n = 5
// findex = 0
// mid = 0 + 4 / 2 = 2
// lindx = 4;

void Sort(std::vector<int>& arr, int start, int end) {
	int mid = (start + end) / 2;

	int i = start, j = mid + 1;

	std::vector<int> arr1;

	// sort array
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			arr1.push_back(arr[i++]);
		}
		else {
			arr1.push_back(arr[j++]);
		}
	}

	while (i <= mid) {
		arr1.push_back(arr[i++]);
	}

	while (j <= end) {
		arr1.push_back(arr[j++]);
	}


	// Print arr1
	for (int k = start; k <= end; ++k) {
		arr[k] = arr1[k - start];
	}
}

void mergeSort(std::vector<int>& arr, int start, int end) {
	// base case
	if (start == end) {
		return;
	}

	// recursive case
	int mid = (start + end) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);

	Sort(arr, start, end);
}

int main() {
	int size = 0;

	std::cin >> size;

	std::vector<int> arr(size);

	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	mergeSort(arr, 0, size - 1);

	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}
