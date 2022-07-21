#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>
#include <climits>

void calculate_Character_Frequency(string input) {
	int max = INT_MIN;
	int freq[256] = { 0 };
	int len = input.length();
	char answer = ' ';

	for (int i = 0; i < len; ++i) {
		freq[input[i]]++;
	}

	for (int i = 0; i < len; ++i) {
		if (max < freq[input[i]]) {
			max = freq[input[i]];
			answer = input[i];
		}
	}

	cout << answer << endl;
}

int main() {
	string input = " ";

	getline(cin, input);

	calculate_Character_Frequency(input);

	return 0;
}
