#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    long long int n1, n2, max;

    cin >> n1 >> n2;

    max = (n1 > n2) ? n1 : n2;

    do {
        if ((max % n1 == 0) && (max % n2 == 0)) {
            cout << max ;
            break;
        }
        else {
            ++max;
        }
    } while (true);

    return 0;
}
