#include <iostream>
#include <vector>
#include <algorithm>

long long Nth_Ugly(int n) {
    if (n == 1) {
        return 1;
    }

    std::vector<long long> dp(n);
    int f2 = 0, f3 = 0, f5 = 0;

    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = std::min({ dp[f2] * 2, dp[f3] * 3, dp[f5] * 5 });

        if (dp[i] == dp[f2] * 2) {
            ++f2;
        }
        if (dp[i] == dp[f3] * 3) {
            ++f3;
        }
        if (dp[i] == dp[f5] * 5) {
            ++f5;
        }
    }

    return dp[n-1];
}

int main() {
	int test = 0;
	std::cin >> test;

	while (test--) {
        int input = 0;
        std::cin >> input;

        std::cout << Nth_Ugly(input) << std::endl;
	}

	return 0;
}
