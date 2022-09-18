#include <iostream>
#include <string>
#include <stack>

int calc_parenthesis(std::string& inp) {
	// count for counting valid parenthesis
	int count = 0;

	// Stack for storing individual parenthesis
	std::stack<int> st;
	// Push -1 initially, it will be subtracted from i th closing bracket
	// element to get the total number of valid parentheses.
	st.push(-1);

	// Start loop from 0 to length of the string
	for (int i = 0; i < inp.length(); ++i) {
		// If character is '(' i,e. opening curved bracket
		// then push i inside the stack.
		if (inp[i] == '(') {
			st.push(i);
		}
		// If character is ')' i,e. closing curved bracket then
		else {
			// Pop the top most element i,e. i - 1
			if (!st.empty()) {
				st.pop();
			}

			// After popping i - 1 element if stack not empty then
			// count will hold the maximum of count and i - st.top() value.
			if (!st.empty()) {
				count = std::max(count, i - st.top());
			}
		}
	}

	// return count
	return count;
}

int main() {
	// Input Parentheses string
	std::string inp = " ";
	std::getline(std::cin, inp);

	// Print the number of valid parentheses.
	std::cout << calc_parenthesis(inp) << std::endl;

	return 0;
}
