#include <iostream>
#include <vector>
#include <string>

void generate_parentheses(std::string output, std::vector<std::string>& ans, int open, int close) {
	// --> base case
	if (open == 0 && close == 0) {
		ans.push_back(output);
		return;
	}

	// --> recursive case

	// '(' has higher value than ')' it means we will first add '('
	// in output and condition will only work until open is greater than 0
	// i.e, open will work for n to 1
	if (open > 0) {
		generate_parentheses(output + '(', ans, open - 1, close);
	}
	// After adding '(', we will add ')'.
	// Close will work until it is greater than open.
	if (close > open) {
		generate_parentheses(output + ')', ans, open, close - 1);
	}
}

int main() {
	// Input the number of sequences to form
	int n = 0;
	std::cin >> n;

	// String vector containing answers
	std::vector<std::string> ans;

	// Generate sequence
	generate_parentheses("", ans, n, n);

	// Print all elements.
	for (int i = ans.size() - 1; i >= 0; --i) {
		std::cout << ans[i] << std::endl;
	}

	return 0;

	// Algorithm which is used in this question is simple.
	// In the first recursion call we are adding '(' and in the second recursion call
	// we are adding ')'. Which means the head will start from '('.

	// Two variables open-->referring to "("  and
	// close-->referring to are used to keep the track
	// of opening and closing brackets. if n=2 it means
	// only two opening and two closing brackets can be
	// used to form sequence.
}
