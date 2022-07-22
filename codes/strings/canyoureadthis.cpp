#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

void printWords(string input) {
	int len = input.length() - 1;

	for (int i = 0; i <= len; ++i) {
		cout << input[i];
		if (input[i + 1] >= 'A' && input[i + 1] <= 'Z') {
			cout << '\n';
		}
	}

	cout << endl;

}

int main() {
	string input = " ";

	getline(cin, input);

	printWords(input);

	return 0;
}
