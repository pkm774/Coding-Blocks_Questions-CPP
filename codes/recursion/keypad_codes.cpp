#include <iostream>
#include <vector>
#include <string>

// Global const vector keypad having strings stored
// in similar manner to keypad phone.
const std::vector<std::string> \
keypad = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz" };

// global variable count for counting
// number of possible outputs
int count = 0;

void keypad_recursion(std::string input, int indx, std::string ans) {
	// base case
	if (indx == input.size()) {
		// print answer
		std::cout << ans << " ";
		// increment count
		++count;
		// return to called stack
		return;
	}

	// recursive case

	// Conversion of single string character into int
	int digit = input[indx] - '0';

	// J starting from 0
	// if digit = 1 i.e, abc then numpad[digit].size()=3
	// therefore j = 0, 1, 2
	for (int j = 0; j < keypad[digit].size(); ++j) {
		// increment index with one and pass the ans string
		// after adding numpad[1][0] for digit = 1
		// for j=0 recursive call
		keypad_recursion(input, indx + 1, ans + keypad[digit][j]);
	}

}

int main() {
	std::string input = " ";
	std::getline(std::cin, input);

	keypad_recursion(input, 0, "");
	std::cout << '\n' << count << std::endl;

	count = 0;

	return 0;
}

/*
OUTPUT:
	ad ae af bd be bf cd ce cf
	9

EXPLANATION:
	can correspond to 'a' , 'b' or 'c' .
	2 can correspond to 'd', 'e' or 'f'.
	We print all combinations of these
*/
