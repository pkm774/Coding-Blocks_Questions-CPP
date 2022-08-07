// Output Format
// Tab separated(*)
//
// Sample Input
// 5
//
// Sample Output
//*
//* *
//* * *
//* * * *
//* * * * *

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void recursionStars(int n) {
	// base case
	if (n == 0) {
		return;
	}

	// recursive case
	recursionStars(n - 1);

	for (int i = 1; i <= n; ++i) {
		cout << '*' << '\t';
	}

	cout << endl;
}

int main() {
	int n = 0;

	cin >> n;

	recursionStars(n);

	return 0;
}
