#include <iostream>
#include <vector>
#include <string>

void Dictionary_Order_Smaller(std::string input, int index, std::string output) {
	// --> base case
	// If index becomes equal to the length of input string
	// then print answer and return.
	if (index == input.length()) {
		std::cout << output << std::endl;
		return;
	}

	// --> recursive case
	// Start j from the index value upto input.length() - 1 times.
	for (int j = index; j < input.length(); ++j) {
		// Swap the character at index with character at jth index.
		std::swap(input[index], input[j]);
		// Call for recursion by incrementing the index value for next character
		// and adding the index character in output string.
		Dictionary_Order_Smaller(input, index + 1, output + input[index]);
		// Backtrack to create original string for next jth call.
		std::swap(input[index], input[j]);
	}
}

int main() {
	// Input string
	std::string input = " ";
	std::getline(std::cin, input);

	// Recursion call
	Dictionary_Order_Smaller(input, 0, "");

	return 0;
}
