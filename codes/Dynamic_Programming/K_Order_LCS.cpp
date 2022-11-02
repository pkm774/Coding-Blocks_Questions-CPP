#include <iostream>

#define boost std::ios_base::sync_with_stdio(false)
#define endl '\n'

long long N[2001]{};
long long M[2001]{};
long long dp[2001][2001][6]{};

long long LCS(long long N[], int i, long long M[], int j, int k) {
	// --> base case
	// when i or j become -1 then return 0;
	if (i == -1 || j == -1) {
		return 0;
	}

	// If values of dp[i][j][k] had been calculated
	// before then return the value instead of calculating again.
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}

	// If element at i in N array and element at j
	// in M array are same then calculate for
	// remaining elements
	if (N[i] == M[j]) {
		return 1 + LCS(N, i - 1, M, j - 1, k);
	}

	// If elements are not same at i and j index of N and M array
	// then check for maximum value from N with remaining i - 1 elements,
	// M with remaining j - 1 elements, and LCS with k - 1.
	long long op1 = LCS(N, i - 1, M, j, k);
	long long op2 = LCS(N, i, M, j - 1, k);

	// Initially op3 will hold -1
	long long op3 = -1;
	// If k is greater than 0 then calculate sequence.
	if (k > 0) {
		op3 = 1 + LCS(N, i - 1, M, j - 1, k - 1);
	}

	// Store maximum from op1, op2 and op3 at i,j,k position in dp array.
	// Return stored value
	return dp[i][j][k] = std::max(op1, std::max(op2, op3));
}

int main() {
	// Disable sync_with_stdio
	boost;
	// tie cout with cin
	std::cin.tie(0);

	// Get n, m, k
	int n, m, k;
	std::cin >> n >> m >> k;

	// Fill N array with n number of elements
	for (int i = 0; i < n; ++i) {
		std::cin >> N[i];
	}

	// Fill M array with m number of elements
	for (int i = 0; i < m; ++i) {
		std::cin >> M[i];
	}

	// Fill dp array with -1
	memset(dp, -1, sizeof(dp));

	// Get LCS
	std::cout << LCS(N, n - 1, M, m - 1, k) << endl;

	return 0;
}


/*
Problem :
--------------
Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem.
Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it
in a flash. To complicate matters, a twist was introduced in the problem.

In addition to the two sequences, an additional parameter k was introduced.
A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change
atmost k elements in the first sequence to any value you wish to. Can you help Mancunian
solve this version of the classical problem?

Input Format :
---------------
The first line contains three integers N, M and k, denoting the lengths of the first
and second sequences and the value of the provided parameter respectively. The second line
contains N integers denoting the elements of the first sequence. The third line contains
M integers denoting the elements of the second sequence.

Constraints :
---------------
1 <= N, M <= 2000
1 <= k <= 5
1 <= element in any sequence <= 109

Output Format :
---------------
Print the answer in a new line.

Sample Input:
---------------
5 5 1
1 2 3 4 5
5 3 1 4 2

Sample Output:
---------------
3

*/