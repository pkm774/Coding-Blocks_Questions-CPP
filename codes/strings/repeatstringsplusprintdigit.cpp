#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include <string>
#include <climits>

void repeat_string(string input, int repeat, int no) {
	int len = input.length();
	string news = " ";

	news = input;
	for (int i = 0; i < repeat - 1; ++i) {
		news = news + input;
	}
	cout << news;
	cout << endl;

	cout << news[no - 1] << endl;
}

int main() {
	string input = " ";
	int repeat = 0, no = 0;

	getline(cin, input);
	cin >> repeat >> no;

	repeat_string(input, repeat, no);

	return 0;
}
