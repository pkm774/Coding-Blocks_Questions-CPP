#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define nine 9

int reverseNum(long long int num) {
	int mod = 0;
	long long rev = 0;

	while (num > 0) {
		mod = num % 10;
		rev = (rev * 10) + mod;
		num /= 10;
	}

	return rev;
}

void invertNumber(long long int num) {
	int mod = 0, sub = 0;
	long long fnum = 0;

	while (num > 0) {

		mod = num % 10;
		sub = nine - mod;
		if (sub < mod) {
			fnum = (fnum * 10) + sub;
		}
		else {
			fnum = (fnum * 10) + mod;
		}
		num /= 10;
	}

	cout << fnum << endl;
}

int main() {
	long long int num = 0;

	cin >> num;

	long long int newnum = reverseNum(num);

	invertNumber(newnum);

	return 0;
}
