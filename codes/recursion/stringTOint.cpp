#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::string;

int stringToint(string s, int size) {

	// base case
	if (size < 0) {
		return 0;
	}

	char ch = s[size];
	int num = ch - '0';

	return stringToint(s, size - 1) * 10 + num;
}


int main() {
	string num = " ";

	cin >> num;

	int size = num.length();

	if (size < 0 && size > 10) {
		return 0;
	}

	cout << stringToint(num, size - 1) << endl;

	return 0;
}
