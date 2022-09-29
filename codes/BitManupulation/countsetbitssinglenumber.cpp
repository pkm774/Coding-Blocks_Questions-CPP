#include <iostream>

using namespace std;

void countSetBits(int num) {
	int count = 0;

		while (num != 0) {
			count += (num & 1);
			num >>= 1;
		}

	cout << count << endl;
}

int main()
{
	int test = 0, num = 0;

	cin >> test;

	while(test--){
		cin>>num;
		countSetBits(num);
	}

	return 0;
}
