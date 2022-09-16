#include <iostream>
#include <vector>
#include <string>

// Global const vector table having
// custom strings stored in it similar to question
const std::vector<std::string> \
	table = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void smart_keypad_recursion(std::string input, int indx, std::string ans) {
	// base case
	if (indx == input.size()) {
		// print answer
		std::cout << ans << std::endl;
		// return to called stack
		return;
	}

	// recursive case

	// Conversion of single string character into int
	int digit = input[indx] - '0';

	// J starting from 0
	// if digit = 1 i.e, ".+@$" then numpad[digit].size()=4
	// therefore j = 0, 1, 2, 3
	for (int j = 0; j < table[digit].size(); ++j) {
		// increment index with one and pass the ans string
		// after adding numpad[1][0] for digit = 1
		// for j=0 recursive call
		smart_keypad_recursion(input, indx + 1, ans + table[digit][j]);
	}

}

int main() {
	std::string input = " ";
	std::getline(std::cin, input);

	smart_keypad_recursion(input, 0, "");

	return 0;
}

/*
OUTPUT:
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
*/
