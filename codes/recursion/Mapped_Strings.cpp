#include <iostream>
#include <vector>
#include <string>

std::vector<char> alphabets = { '0','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', \
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

void Mapped_Strings(std::string input, int index, std::string output, std::vector<std::string>& arrlist) {
	// --> base case
	// ***************************************************************************
	// When index becomes equal to string length
	if (index == input.length()) {
		// Push resulting string inside string vector arrlist
		arrlist.push_back(output);
		// Return
		return;
	}

	// Extract index number from given input string
	int digit1 = input[index] - '0';

	// Declare and initialize the digit with 0.
	int digit2 = 0;
	// If index+1 is less than the input string length
	// then create a number by multiplying digit1 with 10
	// and then adding index+1 digit to it.
	if ((index + 1 < input.length())) {
		digit2 = digit1 * 10 + (input[index + 1] - '0');
	}
	// Else if index+1 is greater than the input string length
	// then instead of adding index+1 digit to it, simply add 0.
	else {
		digit2 = digit1 * 10 + 0;
	}
	// one line code for above --> int digit2 = digit1 * 10 + ((index + 1 < input.length()) ? (input[index + 1] - '0') : 0);

	// --> recursive case
	// ***************************************************************************
	// Create the first sequence with digit1
	Mapped_Strings(input, index + 1, output + alphabets[digit1], arrlist);

	// Check for : index+1 is less than input string size
	//           : digit2 lies between range 1 to 26 including them.
	// if both conditions are true then
	// create sequence with next index and digit2 element.
	if (index + 1 < input.size() && digit2 >= 1 && digit2 <= 26) {
		Mapped_Strings(input, index + 2, output + alphabets[digit2], arrlist);
	}
}

int main() {
	// Input string
	std::string input = " ";
	std::getline(std::cin, input);

	// Array vector for inserting results
	std::vector<std::string> arrlist;

	// Recursion call
	Mapped_Strings(input, 0, "", arrlist);

	// Output
	for (int i = 0; i < arrlist.size(); ++i) {
		std::cout << arrlist[i] << std::endl;
	}

	return 0;
}

/*
Sample Input
123
Sample Output
ABC
AW
LC
Explanation
'1' '2' '3' = ABC
'1' '23' = AW
'12' '3' = LC
*/
