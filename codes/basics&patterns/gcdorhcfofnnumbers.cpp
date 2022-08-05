#include<iostream>

using std::cin;
using std::cout;
using std::endl;

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n)
{
	int result = arr[0];
	for (int i = 1; i < n; i++)
	{
		result = gcd(arr[i], result);

		if (result == 1)
		{
			return 1;
		}
	}
	return result;
}

int main() {
	int size;

	cin >> size;

	// Check if the size of the array is valid else return 0
	if (size <= 0 && size > 10) {
		return 0;
	}

	// Create dynamic array of size
	int* arr{ new int[size] {0} };

	// Input numbers
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	cout << findGCD(arr, size) << endl;

	return 0;
}
