#include <iostream>
#include <vector>

void recur_subset(std::vector<int> arr, std::vector<int> output,
	std::vector<std::vector<int>>& ans_arr, int index) {

	// base case
	if (index == arr.size()) {
		ans_arr.push_back(output);
		return;
	}

	// --> Exclude recursive case.
	// Skip pushing of arr[index] value inside output vector.
	recur_subset(arr, output, ans_arr, index + 1);

	// --> Include recursive case.
	// Push arr[index] value into output vector
	// and make include recursive call.
	output.push_back(arr[index]);
	recur_subset(arr, output, ans_arr, index + 1);
}

std::vector<std::vector<int>> sub_sets(std::vector<int> arr) {

	// Output vector for containing subsets
	std::vector<int> output;
	// 2D vector for containing output
	std::vector<std::vector<int>> ans_arr;

	// Recursion call
	recur_subset(arr, output, ans_arr, 0);

	// Return 2D ans_arr vector
	return ans_arr;
}

int main() {
	// Input vector size
	int size = 0;
	std::cin >> size;

	// input vector;
	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	// output 2D vector
	std::vector<std::vector<int>> output = sub_sets(arr);

	// Print powerset of given array or vector elements
	for (int i = 0; i < output.size(); ++i) {
		for (int j = 0; j < output[i].size(); ++j) {
			std::cout << output[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
