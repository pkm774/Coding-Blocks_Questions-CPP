#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printWords(int num) {
	//base case
	if (num == 0) {
		return;
	}

	int div = num % 10;
	cout << div << ' ';

	//recursive case
	printWords(num / 10);
}

int main() {
	int num = 0;

	cin >> num;

	printWords(num);

	return 0;
}
