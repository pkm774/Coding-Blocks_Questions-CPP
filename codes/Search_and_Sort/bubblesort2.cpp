#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int size = 0, i, j;
	int temp = 0;
	long arr[100000];
	cin >> size;

	for (i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	for (i = 0; i < size - 1; ++i) {
		for (j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j + 1], arr[j]);
			}
			else {
				continue;
			}
		}
	}

	for (i = 0; i < size; ++i) {
		cout << arr[i]<<endl;
	}

	return 0;
}
