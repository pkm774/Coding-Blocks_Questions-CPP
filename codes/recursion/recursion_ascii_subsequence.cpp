#include <iostream>
#include <vector>
#include <string>

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

	// --> include ASCII case
	// Here integer value of input[index] will be included in output.
	// Extract ASCII value of character in ascii variable and
	// add ascii to the output after converting it to string.
	// int ascii = int(input[indx]);
	// from above ascii variable can be used insize to_string()
	recur_subseq(input, output + std::to_string(int(ch)), indx + 1);
}

int main() {
	std::string input{};
	std::string output{};

	std::cin >> input;

	recur_subseq(input, output, 0);
	std::cout << '\n' << count << std::endl;

	return 0;
}
