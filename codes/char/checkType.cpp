#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>


int main() {
	char ch = ' ';

	cin >> ch;

	if (ch >= 'a' && ch <= 'z') {
		cout << 'L' << endl;
	}
	else if (ch >= 'A' && ch <= 'Z') {
		cout << 'U' << endl;
	}
	else { cout << 'I' << endl; }

	return 0;
}
