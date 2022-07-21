#include <iostream>

using namespace std;

int main() {
    int i, index, n, selement, arr[100]{};
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> selement;
    for (i = 0; i < n; ++i) {
        if (arr[i] == selement) {
            index = i;
            break;
        }
    }
    cout << index << endl;
    return 0;

}
