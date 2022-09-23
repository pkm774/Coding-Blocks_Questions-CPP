#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::string;

bool comp(string a, string b) {
	if ((a.size() <= b.size()) && (b.substr(0, a.size())) == a) {
		return false;
	}
	else if ((b.size() <= a.size()) && (a.substr(0, b.size())) == b) {
		return true;
	}
	else {
		return a < b;
	}
}

int main() {
	int total = 0;

	cin >> total;

	if (total < 0 || total > 1000) {
		return 0;
	}

	string* arr{ new string[1000]{" "}};

	for (int i = 0; i < total; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < total; i++) {
		for (int j = i; j < total; j++) {
			if (!comp(arr[i], arr[j])) {
				arr[i].swap(arr[j]);
			}
		}
	}

	for (int i = 0; i < total; i++) {
		cout << arr[i] << endl;
	}

	delete[] arr;

	return 0;
}
