#include <iostream>

using namespace std;

int main() {
    int num, i, j;

    cin >> num;

    for (i = num; i >= 1; --i) {
        if (i % 2 != 0) {
            cout << i << '\n';
            cout << ' ' << endl;
        }
    }
    for (j = 1; j <= num; ++j) {
        if (j % 2 == 0) {
            cout << j << '\n';
            cout << ' ' << endl;
        }
    }
    return 0;
}
