#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    int* ans{ new int [n + 1] {0} };

    for (int i = 0; i <= n; ++i) {
        int count = 0;
        int num = i;
        while (num != 0) {
            if ((num & 1) == 1) {
                count++;
            }
            num = num >> 1;
        }
        ans[i] = count;
    }

    for (int i = 0; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    delete[] ans;

    return 0;
}
