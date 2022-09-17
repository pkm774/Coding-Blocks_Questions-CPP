#include <iostream>
#include <string>

void duplicate_character_formatting(std::string input, int index, std::string& output) {
	// base case
	if (index == input.length()) {
		return;
	}

	// Store input[index] value in ch variable.
	char ch = input[index];
	// Check if ch is similar to its successor
	// if yes then first add ch in output then add '*' after it.
	if (ch == input[index + 1]) {
		output = output + ch + "*";
	}
	// If not then simply ad ch to output.
	else {
		output = output + ch;
	}

	// recursive case
	duplicate_character_formatting(input, index + 1, output);
}

int main() {
	std::string input{};
	std::string output{};

	std::getline(std::cin, input);

	duplicate_character_formatting(input, 0, output);

	std::cout << output;

	return 0;
}
