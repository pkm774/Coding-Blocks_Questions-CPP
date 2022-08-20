#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/// <summary>
/// Calculate total steps required to reach nthstair with given number of steps.
/// </summary>
/// <param name="nthstair"> : nth stair to reach</param>
/// <param name="steps"> : in total number of steps</param>
/// Example steps = 3, means total number of steps he can take only are 1,2 and 3 steps at a time.
/// <returns> return total number of steps</returns>
int NstairCase(int nthstair, int steps) {
    // base case
    // it means step is negative which mean person doesn't exist to jump
    if (nthstair < 0) {
        return 0;
    }
    // it means step is 0 which mean person can move only one step
    if (nthstair == 0) {
        return 1;
    }

    // recursive case
    int sum = 0;
    for (int i = 1; i <= steps; ++i) {
        sum += NstairCase(nthstair - i, steps);
    }

    return sum;
}

int main() {
    int nthstair = 0, steps = 0;
    // Example nthstair = 5
    //         steps = 4 i.e 1 , 2 , 3 and 4
    //         total number of steps = 15
    cin >> nthstair >> steps;

    cout << NstairCase(nthstair, steps) << endl;

    return 0;
}
