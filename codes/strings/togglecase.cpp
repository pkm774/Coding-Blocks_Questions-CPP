#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

void toggle_case(string input) {

	int len = input.length();

	for (int i = 0; i < len; ++i) {
		if (input[i] >= 'a' && input[i] <= 'z') {
			input[i] = input[i] - 32;
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] = input[i] + 32;
		}
	}

	cout << input;
	cout << endl;
}

int main() {
	string input = " ";

	getline(cin, input);

	toggle_case(input);

	return 0;
}
