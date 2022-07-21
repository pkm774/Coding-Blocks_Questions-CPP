#include <iostream>
#include <string>

using namespace std;

string compareNumber(int element, string val) {
	string cval1, cval2, fval;
	string val1 = to_string(element);
	string val2 = val;

	if (val1 == val2) {
		cval1 = val2;
		cval2 = val2;
	}
	else {
		cval1 = val1 + val2;
		cval2 = val2 + val1;
	}

	if (cval1 > cval2) {
		fval = cval1;
	}
	else {
		fval = cval2;
	}

	return fval;
}

void formBiggest(int* array, int size) {
	string value = to_string(array[0]);
	for (int i = 0; i < size; ++i) {
		value = compareNumber(array[i], value);
	}
	cout << value << endl;
}

int main() {
	int testcase = 0, size = 0;
	int array[100000] = { 0 };

	cin >> testcase;

	for (int i = 1; i <= testcase; ++i) {
		cin >> size;

		for (int j = 0; j < size; ++j) {
			cin >> array[j];
		}
		formBiggest(array, size);
	}

	return 0;
}
