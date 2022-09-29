#include<iostream>
#include<cmath>

using namespace std;

int main() {
	long long num, i = 0;
	long long int mod, newnum = 0, number = 0;
	cin >> num;
	if (num == 0) {
		number = 5;
	}
	else {
		while (num) {
			mod = num % 10;
			if (mod == 0) {
				mod = 5;
			}
			newnum = newnum * 10 + mod;
			num /= 10;
		}
		mod = 0;
		while (newnum) {
			mod = newnum % 10;
			number = number * 10 + mod;
			newnum /= 10;
		}
	}
	cout << number << endl;
	return 0;
}
