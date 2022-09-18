#include <iostream>
#include <vector>
#include <string>

void split_array(std::vector<int>& arr, int index, int& count, int sum, std::vector<bool> checkElement) {

	// --> base case
	// Return when index becomes equal to arr.size()
	if (index == arr.size()) {

		// Variable included_sum holds the sum value
		// of included elements
		int included_sum = 0;
		// Calculate sum
		for (int j = 0; j < arr.size(); ++j) {
			if (checkElement[j] == true) {
				included_sum += arr[j];
			}
		}

		// If included_sum is equal to half the sum
		// then print the elements from the vector container
		if (included_sum == sum) {
			// Print the first part which is included and is equal to the sum.
			for (int j = 0; j < arr.size(); ++j) {
				if (checkElement[j] == true) {
					std::cout << arr[j] << " ";
				}
			}
			std::cout << "and ";
			// Print the remaining part which is not included
			// but will be equal to the sum.
			for (int j = 0; j < arr.size(); ++j) {
				if (checkElement[j] == false) {
					std::cout << arr[j] << " ";
				}
			}
			std::cout << std::endl;
			++count;
		}

		// Return baby !
		return;
	}

	// --> recursive case

	// Include current element for addition & checking.
	checkElement[index] = true;
	split_array(arr, index + 1, count, sum, checkElement);

	// Exclude current element from addition & checking.
	checkElement[index] = false;
	split_array(arr, index + 1, count, sum, checkElement);
}

int main() {
	int size = 0;
	std::cin >> size;

	// Check for only array which can be divided into
	// subarrays of the equal sum.
	int sum = 0;

	// Create an input vector and fill it with input containers.
	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
		// Calculate the sum of elements.
		sum += arr[i];
	}

	// If sum % 2 is not equal to 0
	// it means subarrays can not be formed with given elements.
	if (sum % 2 != 0) {
		// Giving output is necessary before returning.
		std::cout << 0;
		return 0;
	}

	// Divide the sum by 2 to pass it in the recursion function
	// elements will be divided according to it.
	sum /= 2;

	// Count variable for counting the number of outputs.
	int count = 0;

	// Create a boolean vector and fill it with zeroes.
	std::vector<bool> checkElement(size, false);

	split_array(arr, 0, count, sum, checkElement);
	std::cout << count << std::endl;

	return 0;
}
