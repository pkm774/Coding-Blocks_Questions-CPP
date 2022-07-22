#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

void string_reverse(string input) {

	int len = input.length();

	for (int i = len - 1; i >= 0; --i) {
		cout << input[i];
	}

	cout << endl;
}

int main() {
	string input = " ";

	getline(cin, input);

	string_reverse(input);

	return 0;
}
