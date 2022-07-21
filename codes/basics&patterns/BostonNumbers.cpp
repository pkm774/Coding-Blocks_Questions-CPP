#include <iostream>
#include <math.h>

using namespace std;

int numberSum(long int input) {
	int div = 0;
	int sum = 0;

	while (input > 0) {
		div = input % 10;
		sum += div;
		input /= 10;
	}

	return sum;
}

int primeFactorSum(long int input) {
	int i, sum = 0, total = 0;

	while (input % 2 == 0)
	{
		sum += 2;
		input = input / 2;
	}

	for (i = 3; i <= sqrt(input); i = i + 2)
	{
		while (input % i == 0)
		{
			sum += i;
			input = input / i;
		}
	}

	if (input > 2) {
		sum += input;
	}

	total = numberSum(sum);
	return total;
}

int main() {
	long int input = 0;
	int numsum = 0, newsum = 0, newsum2 = 0;
	int factorsum = 0, newfactorsum = 0, newfactorsum2 = 0;

	cin >> input;

	numsum = numberSum(input);
	newsum = numberSum(numsum);
	newsum2 = numberSum(newsum);

	factorsum = primeFactorSum(input);
	newfactorsum = numberSum(factorsum);
	newfactorsum2 = numberSum(newfactorsum);

	//cout << newsum2 << endl;
	//cout << newfactorsum2 << endl;

	if (newsum2 == newfactorsum2) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}
