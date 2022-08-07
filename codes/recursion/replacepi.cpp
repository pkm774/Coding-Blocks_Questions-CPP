#include <iostream>
using std::cout;
using std::cin;
using std::endl;

char out[1000000];
int k = 0;

void replace(char* a, int i) {
    // base case
    if (a[i] == '\0') {
        out[k++] = '\0';
        return;
    }

    // recursive case
    if (a[i] == 'p' && a[i + 1] == 'i') {
        out[k++] = '3';
        out[k++] = '.';
        out[k++] = '1';
        out[k++] = '4';
        replace(a, i + 2);
    }
    else {
        out[k++] = a[i];
        replace(a, i + 1);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        // Uisng heap for character allocation
        char* a{ new char {' '} };
        cin >> a;
        replace(a, 0);
        cout << out << endl;
        k = 0;
    }
    return 0;
}
