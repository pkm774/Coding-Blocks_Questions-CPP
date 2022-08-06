#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <cstring>
using std::string;

#include <cmath>
using std::pow;

//----------------------------------------
//      |            |           |
//      |            |           |
//      |            |           |
//  ---------    ---------   ---------
//   " T1 "       " T2 "       " T3 "
//
//   Source     Destination    Helper
//   Tower        Tower        Tower
//-----------------------------------------

void towerOfHanoi(int n, string src, string dest, string helper) {
	//base case
	if (n == 0) {
		return;
	}

	// recursive case
	towerOfHanoi(n - 1, src, helper, dest);
	cout << "Move " << n << "th disc from " << src << " to " << dest << endl;
	towerOfHanoi(n - 1, helper, dest, src);
}

int main() {
	int n;

  // n = total number of discs
	cin >> n;

	towerOfHanoi(n, "T1", "T2", "T3");
	// No of steps i.e, 2^n - 1
	cout << pow(2, n) - 1 << endl;

	return 0;
}
