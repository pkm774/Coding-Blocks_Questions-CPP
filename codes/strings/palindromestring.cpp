#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>

bool checkPalindrome(string inpt) {
	int i = 0;
	auto size = inpt.length() - 1;

	while (i < size)
	{
		// if a mismatch happens
		if (inpt[i] != inpt[size]) {
			return false;
		}
		++i;
		--size;
	}

	return true;
}

int main() {
	string inpt = " ";

	getline(cin, inpt);

	if (checkPalindrome(inpt)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	return 0;
}
