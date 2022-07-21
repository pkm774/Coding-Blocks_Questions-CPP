#include <iostream>

using namespace std;

int conversion(int num, int sb, int db) {
  int ans = 0;
  int mult = 1;

    // Any  Base to Decimal
    while (num != 0) {
        int rem = num % 10;
        ans = ans + rem * mult;
        mult = mult * sb;
        num = num / 10;
    }

    // Refresing the variables
    mult = 1;
    num = ans;
    ans = 0;

    //Decimal to Any number
    while (num != 0) {
        int rem = num % db;
        ans = ans + rem * mult;
        mult = mult * 10;
        num = num / db;
    }

    return ans;
}

int main() {
    int num = 0, sb = 0, db = 0;
    int ans = 0;

    cin >> sb;
    cin >> db;
    cin >> num;

    ans = conversion(num, sb, db);

    cout << ans << endl;

    return 0;
}
