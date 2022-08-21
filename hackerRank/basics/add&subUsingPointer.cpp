#include <iostream>
#include <cstdlib>

using namespace std;

void update(int x, int y){
    int* a = &x;
    int* b = &y;

    cout << *a + *b << endl;
    cout << abs(*a - *b) << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x, y;
    cin >> x >> y;
    update(x, y);
    return 0;
}
