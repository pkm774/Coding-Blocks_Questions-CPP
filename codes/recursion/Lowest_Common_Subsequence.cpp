#include <iostream>
#include <string>
#include <algorithm>

int LCS(int i1, int i2, std::string s1, std::string s2) {
	// --> base case
	// If index character of the string is null
	// return 0.
	if (s1[i1] == '\0' || s2[i2] == '\0') {
		return 0;
	}

	// --> recursive case

	// If both the characters at i1 and i2 index matches
	// with each other then add 1 for both of these characters
	// and increase i1 and i2 with 1 for checking remaining characters.
	else if (s1[i1] == s2[i2])
		return 1 + LCS(i1 + 1, i2 + 1, s1, s2);

	// If characters at i1 and i2 index doesn't matches
	// then call this function recursively two times
	// and return maximum value from both of them.

	// For checking characters :
	// In first call we match current i1 character of s1 with
	// remaining characters of s2.
	// In second call we match remaining character of s1 with
	// i2 character of s2.
	else
		return std::max(LCS(i1, i2 + 1, s1, s2), LCS(i1 + 1, i2, s1, s2));
}

int main() {
	std::string s1, s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);

	std::cout << LCS(0, 0, s1, s2);

	return 0;
}