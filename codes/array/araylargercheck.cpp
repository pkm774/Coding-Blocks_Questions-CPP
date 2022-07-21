#include <iostream>

using namespace std;

int main() {
    int i, j = 1, n, arr[10] = {};
    int largest;
    cout << "Enter total elements of array:" << " ";
    cin >> n;

    for (i = 0; i < n; ++i) {
        cout << "Enter element no " << i + 1 << ": ";
        cin >> arr[i];
    }

    largest = arr[0];
    while (j <= n) {
        if (arr[j] > largest) {
            largest = arr[j];
        }
        ++j;
    }

    cout << "Largest value is :" << largest;

    return 0;
}
