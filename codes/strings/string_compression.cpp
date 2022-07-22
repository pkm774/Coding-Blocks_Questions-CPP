#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

void string_compression(string input) {

	int len = input.length();

	for (int i = 0; i < len;) {
		char ch = input[i];
		int count = 0;
		while (ch == input[i + count]) {
			++count;
		}
		cout << input[i];
		cout << count;
		i = i + count;
	}

	cout << endl;
}

int main() {
	string input = " ";

	getline(cin, input);

	string_compression(input);

	return 0;
}
