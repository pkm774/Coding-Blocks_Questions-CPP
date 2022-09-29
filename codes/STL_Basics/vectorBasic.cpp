#include <iostream>
#include <vector>

// Function to take input through cin
void vec_input(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		std::cin >> vec[i];
	}
}

// Function to take input through push_back()
void vec_input_push(std::vector<int>& vec2, int size) {
	for (int i = 0; i < size; ++i) {
		int temp = 0;
		std::cin >> temp;
		vec2.push_back(temp);
	}
}

// Function for printing elements of vectors
void vec_print(std::vector<int>& vec){
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	// declare number of elements
	int num = 0;
	std::cout << "Enter number of elements: ";
	std::cin >> num;

	// vector array input using cin we require number of elements
	std::vector<int> arr(num);
	std::cout << "Enter number elements for arr: ";
	vec_input(arr);

	// print vector arr;
	std::cout << "Output of arr: ";
	vec_print(arr);
	std::cout << '\n';

	// vector array input using push_back(), size will be passed as arguments;
	std::vector<int> arr2;
	std::cout << "Enter number elements for arr2: ";
	vec_input_push(arr2, num);

	// print vector arr2;
	std::cout << "Output of arr2: ";
	vec_print(arr2);
	std::cout << '\n';


	// copying a vector, its deep copy rather than shallow copy as arrays
	std::vector<int> arr3 = arr;
	std::cout << "Output of arr3 copied from arr is: ";
	vec_print(arr3);

	return 0;
}
