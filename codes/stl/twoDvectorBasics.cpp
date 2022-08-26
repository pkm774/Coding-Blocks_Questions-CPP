#include <iostream>
#include <vector>

// input function with vector passed as reference for avoiding creation of a new copied 2D vector.
// here cin have been used and its convenient because vectors are declared with fixed size.
void take_inp(std::vector<std::vector<int>>& arr, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cin >> arr[i][j];
		}
	}
}


// 2nd input function with vector passed as reference for avoiding creation of a new copied 2D vector.
// for pushing column wise we have to create column vector inside row loop;
// here we are using push_back() and its convinient here because vector is not declared with fixed size;
void take_inp_back(std::vector<std::vector<int>>& arr, int size) {
	for (int i = 0; i < size; ++i) {
		// col vector inside row loop
		std::vector<int> col;
		// loop for column input
		for (int j = 0; j < size; ++j) {
			int colinp = 0;
			std::cin >> colinp;
			// pushing element by element
			col.push_back(colinp);
		}
		// pushing whole col vector in arr;
		arr.push_back(col);
	}
}

// output function with vector passed as reference to print the base 2D vector
void print_vec(std::vector<std::vector<int>>& arr) {
	std::cout << arr.size() << " " << arr[0].size() << std::endl;
	// arr.size() = total row length
	// arr[i].size() = column length of ith row
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int size = 0;
	std::cin >> size;

	// Here we have declared vector in vector (2D vector) with fixed size. How this will work is actually simple.
	// Vector col is declared with size, lets size = 4, therefore vector col will have size 4.
	// Vector inp will be generated of same size = 4 filled with col vector. Imagine containers in container !
	// only cin can be used here as i have already declred vectors with fixed size;
	std::vector<int> col(size);
	std::vector<std::vector<int>> inp(size, col);

	// function to take input
	take_inp(inp, size);
	// function to print input
	print_vec(inp);

	std::cout << std::endl;

	// 2nd 2D vector without fixed size.
	// Column vector will be created during push_back() column wise
	// See take_inp_back() function
	std::vector<std::vector<int>> inp2;

	// function to take input
	take_inp_back(inp2, size);
	// function to print input
	print_vec(inp2);

	return 0;
}
