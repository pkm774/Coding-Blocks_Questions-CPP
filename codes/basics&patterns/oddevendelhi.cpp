#include<iostream>

using namespace std;

int main() {
	int total, numb, i;
	int revnum = 0, sum = 0;
	int div = 0, index = 0;
	int oddsum = 0, evensum = 0;
	int arr;

	cin >> total;

	for (i = 1; i <= total; ++i) {

		revnum = 0;
		oddsum = 0;
		evensum = 0;
		index = 0;

		cin >> numb;
		while (numb != 0) {
			div = numb % 10;
			revnum = revnum * 10 + div;
			numb /= 10;
		}

		div = 0;
		while( revnum != 0) {
			div = revnum % 10;
			++index;
			if (index % 2 != 0) {
				oddsum = oddsum + div;
			}
			else if (index % 2 == 0) {
				evensum = evensum + div;
			}
			revnum /= 10;
		}

		if ((evensum % 2 == 0) && (evensum % 4 == 0)) {
			cout << "Yes" << endl;
		}
		else if ((oddsum % 2 != 0) && (oddsum % 3 == 0)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}
