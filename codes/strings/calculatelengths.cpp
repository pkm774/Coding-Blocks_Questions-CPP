#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>

int main() {
	char string[100] = "";
	int counter = 0, i = 0;

	cin.getline(string, 100);

	while (string[i] != '\0') {
		++counter;
		++i;
	}

	cout << counter << endl;

	return 0;
}
