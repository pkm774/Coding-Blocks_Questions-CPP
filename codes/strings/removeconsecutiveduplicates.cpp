#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

void remove_consecutive_Duplicates(string input) {

	int len = input.length();

	for (int i = 0; i < len; ++i) {
		if (input[i + 1] != input[i]) {
			cout << input[i];
		}
	}

	cout << endl;
}

int main() {
	string input = " ";

	getline(cin, input);

	remove_consecutive_Duplicates(input);

	return 0;
}
