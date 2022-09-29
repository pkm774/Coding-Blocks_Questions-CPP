#include <iostream>

using namespace std;

int main() {
    int num, i, j, k;

    cin >> num;

    for (i = 1; i <= num ; ++i) {
        int left = i;
        int right;
        for (j = 1; j <= i; ++j) {
            cout << left << ' ';
            right = left;
        }
        for (k = num - i; k >= 1; --k) {
            ++right;
            cout << right << ' ';
        }
        cout << endl;
    }
    return 0;
}
