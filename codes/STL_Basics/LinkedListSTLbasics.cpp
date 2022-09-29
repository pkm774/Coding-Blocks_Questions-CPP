#include <iostream>
#include <list>
#include <iterator>

// Function to create Linked List of size size.
// Push  at end concept is used
void input_LL(std::list<int>& LL) {
	int size = 0;
	std::cin >> size;

	while (size--) {
		int data = 0;
		std::cin >> data;

		LL.push_back(data);
	}

}

// Function to print elements of LL using range-based for-loop.
void print_LL(std::list<int> LL) {
	for (auto i : LL) {
		std::cout << i << " ";
	}
}

// Function to print elements of LL using iterators
void print_LL_iterator(std::list<int> LL) {
	std::list<int> ::iterator it;

	for (it = LL.begin(); it != LL.end(); ++it) {
		std::cout << *it << " ";
	}
}

// Main driver function
int main() {
	// creation of Linked List of type int using stl
	std::list<int> LL;

	// Custom function to create n nodes in Linked List
	input_LL(LL);

	// Custom function to print LL using range-based for-loop
	print_LL(LL);

	// Custom function to print LL using iterators
	print_LL_iterator(LL);
}
