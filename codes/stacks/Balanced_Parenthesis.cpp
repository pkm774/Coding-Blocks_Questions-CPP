#include <iostream>
#include <string>
#include <stack>

bool balanced_parenthesis(std::string input) {
	// Parenthesis stack
	std::stack<char> stk;

	for (int i = 0; i < input.length(); ++i) {
		// First check for empty stack
		if (stk.empty()) {
			// If its empty then push the current first bracket
			stk.push(input[i]);
		}
		// Else if input[i] contain closing bracket
		// then pop the matching closing bracket
		else if ((input[i] == '}' && stk.top() == '{') ||
			(input[i] == ')' && stk.top() == '(') ||
			(input[i] == ']' && stk.top() == '[')) {

			// Pop the current element
			stk.pop();
		}
		// Else push the opening input[i].
		else {
			stk.push(input[i]);
		}
	}

	// If the stack becomes empty then the input
	// string contain valid parentheses
	if (stk.empty()) {
		// True
		return true;
	}
	// If the stack is not empty it means
	// either opening or closing bracket pair
	// is not completed
	else {
		// Return false
		// The input string contain valid parentheses
		return false;
	}
}

int main() {
	// Input Parentheses string
	std::string input = " ";
	std::getline(std::cin, input);

	// Print Yes if the input string contains valid parentheses.
	if (balanced_parenthesis(input)) {
		std::cout << "Yes" << std::endl;
	}
	// Else print No.
	else {
		std::cout << "No" << std::endl;
	}

	return 0;
}
