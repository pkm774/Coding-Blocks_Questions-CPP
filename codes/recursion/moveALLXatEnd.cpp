#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::string;

void moveXend(string& s, int size, int i) {

	// base case
	if (i == size) {
		return;
	}

	char ch = s[i];
	if (ch == 'x') {
		for (int j = i; j < size; ++j) {
			s[j] = s[j + 1];
		}
		s[size] = ch;
		moveXend(s, size - 1, i);
	}
	else {
		moveXend(s, size, i + 1);
	}
}


int main() {
	string num = " ";

	cin >> num;

	int size = num.length();

	if (size < 0 && size > 10) {
		return 0;
	}

	moveXend(num, size - 1, 0);

	cout << num << endl;

	return 0;
}
