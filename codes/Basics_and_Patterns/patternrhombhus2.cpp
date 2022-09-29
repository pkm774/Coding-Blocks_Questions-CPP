#include <iostream>

using namespace std;

int main() {
    int num, i, j, centre;
    int k, l, m, n;
    cin >> num;

    // upper full star line
    for (j = 1; j <= num; ++j) {
        cout << '*' << '\t';
    }
    cout << endl;
    // upper middle pattern
    for (k = 1; k <= (num / 2) - 1; k++) {
        // stars
        for (l = num / 2; l >= k; --l) {
            cout << '*' << '\t';
        }
        // space
        for (m = 1; m <= 2 * k - 1; ++m) {
            cout << ' ' << '\t';
        }
        // stars
        for (n = num / 2; n >= k; --n) {
            cout << '*' << '\t';
        }
        cout << endl;
    }
    // centre with 2 stars and num-2 spaces
    for (centre = 1; centre <= num; ++centre) {
        if (centre == 1 || centre == num) {
            cout << '*' << '\t';
        }
        else {
            cout << ' ' << '\t';
        }
    }
    cout << endl;
    // lower middle pattern
    for (k = 1; k <= (num / 2) - 1; k++) {
        // stars
        for (l = 1; l <= k + 1; ++l) {
            cout << '*' << '\t';
        }
        // space
        for (m = 1; m <= num/k - (2*((num/2)-k)); ++m) {
            cout << ' ' << '\t';
        }
        // stars
        for (n = 1; n <= k + 1; ++n) {
            cout << '*' << '\t';
        }
        cout << endl;
    }
    // lower full star line
    for (j = 1; j <= num; ++j) {
        cout << '*' << '\t';
    }
    cout << endl;
    return 0;
}
