#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int LCS(int i1, int i2, std::string s1, std::string s2,
	std::vector<std::vector<int>>& ans) {

	// --> base case
	// If index becomes equal to strings length
	// return 0.
	if (i1 == s1.length() || i2 == s2.length())
		return 0;

	// Check for previous calculated answer at i1th, i2th index.
	else if (ans[i1][i2] != -1)
		return ans[i1][i2];

	// --> recursive case

	// If both the characters at i1 and i2 index matches
	// with each other then add 1 for both of these characters
	// and increase i1 and i2 with 1 for checking remaining characters.

	// Because of memoization we will save answe to i1th, i2th index.
	else if (s1[i1] == s2[i2])
		return ans[i1][i2] = 1 + LCS(i1 + 1, i2 + 1, s1, s2, ans);

	// If characters at i1 and i2 index doesn't matches
	// then call this function recursively two times
	// and return maximum value from both of them.

	// For checking characters :
	// In first call we match current i1 character of s1 with
	// remaining characters of s2.
	// In second call we match remaining character of s1 with
	// i2 character of s2.

	// Because of memoization we will save answe to i1th, i2th index.
	else
		return ans[i1][i2] = std::max(LCS(i1, i2 + 1, s1, s2, ans), LCS(i1 + 1, i2, s1, s2, ans));
}

int main() {
	std::string s1, s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);

	// DP Vector
	std::vector<int> col(s2.length(), -1);
	std::vector<std::vector<int>> ans(s1.length(), col);

	// Function Call
	LCS(0, 0, s1, s2, ans);

	// Filling of answers in array will start
	// from last row, ans 0,0 index will be filles at last.
	// answer at index 0,0 will have the answer.
	std::cout << ans[0][0] << std::endl;

	return 0;
}