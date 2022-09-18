#include <iostream>
#include <set>
#include <string>
#include <algorithm>

void Dictionary_Order_Smaller(std::string input, int index, std::string output, std::set<std::string>& answer) {
	// --> base case
	// If the index becomes equal to the length of the input string
	// then print the answer and return.
	if (index == input.length()) {
		answer.insert(output);
		return;
	}

	// --> recursive case
	// Start j from the index value up to input.length() - 1 times.
	for (int j = index; j < input.length(); ++j) {
		// Swap the character at index with character at jth index.
		std::swap(input[index], input[j]);
		// Call for recursion by incrementing the index value for next character
		// and adding the index character in the output string.
		Dictionary_Order_Smaller(input, index + 1, output + input[index], answer);
		// Backtrack to create the original string for the next jth call.
		std::swap(input[index], input[j]);
	}
}

int main() {
	// Input string
	std::string input = " ";
	std::getline(std::cin, input);

	// String vector for storing answers.
	std::set<std::string> answer;

	// Recursion call
	Dictionary_Order_Smaller(input, 0, "", answer);

	// Function to print sorted strings
	for (auto ans : answer) {
		std::cout << ans << std::endl;
	}

	return 0;
}
