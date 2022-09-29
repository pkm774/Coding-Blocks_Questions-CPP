#include <iostream>

int main() {
	// normal pair example
	std::pair<int, std::string> mypair;

	std::cin >> mypair.first >> mypair.second;

	std::cout << mypair.first << " " << mypair.second << std::endl;

	// creating new pair for copying previous value
	std::pair<int, std::string> mypair2 = mypair;

	// normal copying
	std::cout << "After copying in mypair2: " << std::endl;
	std::cout << mypair.first << " " << mypair.second << std::endl;

	// copying using reference (creating a second name)
	std::pair<int, std::string>& mypair3 = mypair;
	mypair3.first = 8;
	// mypair3 changes will reflect in mypair
	std::cout << "After changing mypair3.first value: " << std::endl;
	std::cout << mypair.first << " " << mypair.second << std::endl;
	std::cout << '\n';

	// pair array to store multiple values dynamically
	// for static allocation we will do
	// std::pair<int, std::string> names[5];
	int size = 0;
	std::cout << "Enter size: ";
	std::cin >> size;
	std::pair<int, std::string>* names = new std::pair<int, std::string>[size];

	for (int i = 0; i < size; ++i) {
		std::cin >> names[i].first >> names[i].second;
	}
	std::cout << "Printing names: " << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << names[i].first << " " << names[i].second;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	delete[] names;
	std::cout << '\n';
	// array operation using pair
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 4, 5, 6 };

	std::pair<int, int> pair_arr[3];

	for (int i = 0; i < 3; ++i) {
		pair_arr[i] = { arr1[i],arr2[i] };
	}
	std::cout << "After pairing: " << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << pair_arr[i].first << " " << pair_arr[i].second << std::endl;
	}

	return 0;
}
