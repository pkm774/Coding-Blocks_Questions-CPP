#include<iostream>

using namespace std;

int main() {
	int i, total, element = 0, arr[100000]{};

	cin >> total;

	for (i = 0; i < total; ++i) {
		cin >> arr[i];
	}

	element = arr[0];
	for (i = 1; i < total; ++i) {
		element = element ^ arr[i];
	}

	cout << element;
	return 0;
}
