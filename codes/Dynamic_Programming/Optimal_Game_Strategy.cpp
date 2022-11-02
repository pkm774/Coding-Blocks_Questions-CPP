// Question me lagaya gya gyan : When things happen to you, assume the worst
//                               when you do something, do the best.

#include <iostream>
#include <vector>

constexpr auto endl = '\n';

int recursive_dp(std::vector<int>& arr, int i, int j, std::vector<std::vector<int>>& dp) {

	// --> Base Case
	if (i > j) {
		return 0;
	}

	// Checking for pre calculated value
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

    // --> Recursive Case
	// arr[i], arr[j] are the options chosen by first player,
	// next time, options will be chosen by the opponent
	// and the first player has to assume that he will get minimum
	// after the opponent chose its options.
	int op1 = arr[i] + std::min(recursive_dp(arr, i + 1, j - 1, dp), recursive_dp(arr, i + 2, j, dp));
	int op2 = arr[j] + std::min(recursive_dp(arr, i, j - 2, dp), recursive_dp(arr, i + 1, j - 1, dp));

	// Memoization
	return dp[i][j] = std::max(op1, op2);
}

void Optimal_Strategy(std::vector<int>& arr, int size) {
	// Dp vector ((size + 1) * (size + 1)) and filled with -1
	std::vector<std::vector<int>> dp(size + 1, std::vector<int>(size + 1, -1));
	// Recursive solution
	std::cout << recursive_dp(arr, 0, size - 1, dp) << endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int size = 0;
	std::cin >> size;

	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
	
	Optimal_Strategy(arr, size);

	return 0;
}