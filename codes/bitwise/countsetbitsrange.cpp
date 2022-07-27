#include <iostream>

using namespace std;

void countSetBits(int num1, int num2) {

	int temp1 = 0;
	int count = 0;

	for (int i = num1; i <= num2; ++i) {
		temp1 = i;
		while (temp1 != 0) {
			count += (temp1 & 1);
			temp1 >>= 1;
		}
	}

	cout << count << endl;
}

int main()
{
	int query = 0, num1 = 0, num2 = 0;

	cin >> query;

	for (int i = 1 ; i <= query; ++i) {
		cin >> num1 >> num2;
		countSetBits(num1, num2);
	}

	return 0;
}
