#include <iostream>
#include <math.h>

using namespace std;

int countDigit(int num)
{
	if (num == 0)
	{
		return 1;
	}
	int count = 0;
	while (num != 0)
	{
		num = num / 10;
		++count;
	}
	return count;
}

int seperate(long long number)
{
	long long newnum = 0;
	int d = 0;
	while (number != 0)
	{
		d = number % 10;
		newnum = newnum * 10 + d;
		number /= 10;
	}
	return newnum;
}

long long armstrong(long long inputnum, int nsize)
{
	int d = 0;
	long long armnum = 0, revnum = 0, received = 0;
	received = inputnum;
	revnum = seperate(received);
	while (revnum != 0)
	{
		d = revnum % 10;
		armnum = armnum + pow(d, nsize);
		revnum /= 10;
	}
	return armnum;
}

int main()
{
	long long inputnum = 0, revnum = 0;
	int nsize = 0;

	cin >> inputnum;

	nsize = countDigit(inputnum);
	revnum = armstrong(inputnum, nsize);

	if (revnum == inputnum)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

	return 0;
}
