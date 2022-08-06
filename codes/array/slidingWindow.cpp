#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <climits>

// 10,4,8,13,20
// 22

void checkProcess(int* arr, int size) {
    int total = 0, sum = 0;
    int max = INT_MIN;

    for (int i = 0; i < size - 1; ++i) {
        sum = arr[i] + arr[ i + 1];

        if (sum > max) {
            max = sum;
        }
    }

    for (int i = 0; i < size; ++i) {
        total = total + arr[i];
    }

    cout << total - max << endl;

}

int main() {
    int size = 0;

    cin >> size;

    if (size < 0) {
        return 0;
    }

    int* arr{ new int[size] {0} };

    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    checkProcess(arr, size);

    delete[] arr;

    return 0;
}
