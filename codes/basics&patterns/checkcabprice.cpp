#include <iostream>
using namespace std;

void checkPrice(int n1, int n2) {
	if (n1 > n2) {
		cout << "SECOND" << endl;
	}
	else if (n2 > n1) {
		cout << "FIRST" << endl;
	}
	else {
		cout << "ANY" << endl;
	}
}

int main() {
	int test = 0, pricea = 0, priceb = 0;

	cin >> test;

	while (test--) {
		cin >> pricea >> priceb;
		checkPrice(pricea, priceb);
	}
	return 0;
}
