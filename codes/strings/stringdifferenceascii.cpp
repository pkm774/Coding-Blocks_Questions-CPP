#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

void string_difference_ascii(string input) {

	int len = input.length();

	for (int i = 0; i < len; ++i) {
		int difference = 0;

		cout << input[i];
		difference = int(input[i + 1]) - int(input[i]);
		if(i != len - 1) {
			cout << difference;
		}
	}

	cout << endl;
}

int main() {
	string input = " ";

	getline(cin, input);

	string_difference_ascii(input);

	return 0;
}
