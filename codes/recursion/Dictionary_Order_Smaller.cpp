#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void Dictionary_Order_Smaller(std::string input, int index, std::string output, std::vector<std::string>& answer) {
	// --> base case
	// If the index becomes equal to the length of the input string
	// then print the answer and return.
	if (index == input.length()) {
		answer.push_back(output);
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

// Comparator function to sort the array of string wrt given conditions
bool string_compare(std::string a, std::string b)
{
	// Check if a string is present as the prefix in another string, then
	// compare the size of the string and return the larger size.
	if (a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0) {
		return a.size() > b.size();
	}
	// Else return lexicographically smallest string
	else {
		return a < b;
	}
}

int main() {
	// Input string
	std::string input = " ";
	std::getline(std::cin, input);

	// String vector for storing answers.
	std::vector<std::string> answer;

	// Recursion call
	Dictionary_Order_Smaller(input, 0, "", answer);

	// Function call to Sort lexicographically
	std::sort(answer.begin(), answer.end(), string_compare);

	// Function to print sorted strings
	for (int i = 0; i < answer.size(); ++i) {
		// Print only those strings which are lexicographically smaller
		// than the input string.
		if (answer[i] < input) {
			std::cout << answer[i] << std::endl;
		}
	}

	return 0;
}
