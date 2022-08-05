#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

string numbs[] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

void printWordsFront(int num) {

	if (num == 0) {
		return;
	}

	printWordsFront(num / 10);

	int div = num % 10;
	cout << numbs[div] << ' ';
}

void printWordsBack(int num) {

	if (num == 0) {
		return;
	}

	int div = num % 10;
	cout << numbs[div] << ' ';

	printWordsBack(num / 10);
}

int main() {
	int num = 0;

	cin >> num;

	cout << "From Front : " << endl;
	printWordsFront(num);
	cout << endl;
	cout << "From Back : " << endl;
	printWordsBack(num);

	return 0;
}
