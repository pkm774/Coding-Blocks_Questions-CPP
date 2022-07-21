#include <iostream>
#include <math.h>
using namespace std;

void printarmstrong(int start, int end) {
	int i, temp1, temp2, remainder;
	int power = 0, result = 0;

	for (i = start + 1; i < end; ++i)
	{
		temp1 = i;
		temp2 = i;

		while (temp1 != 0)
		{
			temp1 /= 10;
			++power;
		}

		while (temp2 != 0)
		{
			remainder = temp2 % 10;
			result += pow(remainder, power);
			temp2 /= 10;
		}

		if (result == i) {
			cout << i << endl;
		}

		power = 0;
		result = 0;

	}
}


int main()
{
	int start, end;

	cin >> start >> end;

	printarmstrong(start, end);
	return 0;
}
