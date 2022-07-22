#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

void oddeven_character(string input) {

	int len = input.length();

	for (int i = 0; i < len; ++i) {
		if (i % 2 == 0) {
			input[i] = input[i] + 1;
		}
		else {
			input[i] = input[i] - 1;
		}
	}

	cout << input;
	cout << endl;
}

int main() {
	string input = " ";

	getline(cin, input);

	oddeven_character(input);

	return 0;
}
