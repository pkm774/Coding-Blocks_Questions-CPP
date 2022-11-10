#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	unordered_map<int, int> numbers;

	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	numbers[4] = 5;

	cout << "Using ranged loop\n";
	for (auto &it : numbers) {
		cout << "Key: " << it.first << " Value: " << it.second << '\n';
	}

	cout << "\nUsing iterator\n";
	unordered_map<int, int> ::iterator it;
	for (it = numbers.begin(); it != numbers.end(); ++it) {
		cout << "Key: " << it->first << " Value: " << it->second << '\n';
	}

	cout << '\n';

	int key = 0;
	cout << "Enter key: ";
	cin >> key;
	if (numbers.count(key)) {
		cout << "Key " << key << " contains " << numbers[key] << " as its value";
	}
	else {
		cout << "Key " << key << " doesn't exist !";
	}

	cout << '\n';

	return 0;
}