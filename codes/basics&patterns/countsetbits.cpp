#include <iostream>

using namespace std;

int main() {
    int num, i = 1, val, total;
    cin >> num;

    while (i <= num) {
        total = 0;
        cin >> val;
        while (val) {
            total += val & 1;
            val >>= 1;
        }
        cout << total << endl;
        ++i;
    }

    return 0;
}
