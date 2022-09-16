#include <iostream>
#include <vector>

int count = 0;

void recur_subseq(std::string input, std::string output, int indx) {
	// base case
	if (indx == input.size()) {
		std::cout << output << " ";
		++count;
		return;
	}

	// --> exclude recursive case
	// Here input[index] will be excluded from output.
	recur_subseq(input, output, indx + 1);

	// --> include recursive case
	// Here input[index] will be included in output.
	// Include index character in output
	// i.e, for input=abcd, input[0]=a and add 'a'.
	char ch = input[indx];
	recur_subseq(input, output + ch, indx + 1);
}

int main() {
	std::string input{};
	std::string output{};

	std::cin >> input;

	recur_subseq(input, output, 0);
	std::cout << '\n' << count << std::endl;

	return 0;
}
