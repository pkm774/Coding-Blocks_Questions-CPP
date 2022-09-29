#include <iostream>

using namespace std;

int main() {
    int num, i = 1, j;

    cin >> num;

    while (i <= num) {
        for (j = 1; j <= i; ++j) {
            cout << '*';
        }
        cout << endl;
        cout << ' ' << endl;
        ++i;
    }
    return 0;
}
