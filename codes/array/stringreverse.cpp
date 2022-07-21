#include <iostream>

using namespace std;

int calclen(char* arr) {
	int i = 0;
	int total = 0;

	while (arr[i] != '\0') {
		total++;
		i++;
	}

	return total;
}

int main() {
	char a[100] = "";
	cin.getline(a, 100);

	int len = calclen(a);

	int i = 0;
	int j = len - 1;

	while (j > i) {
		swap(a[i], a[j]);
		i++;
		j--;
	}

	cout << a;

	return 0;
}
