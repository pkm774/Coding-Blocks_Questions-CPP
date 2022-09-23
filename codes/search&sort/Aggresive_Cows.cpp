#include <iostream>
#include <algorithm>

bool seperation_Possible(long long* pos, long long mid, int n, int c) {
	// Store the starting position in prev variable
	long long prev = pos[0];

	// Check for every position after prev
	for (int i = 1; i < n; ++i) {
		// First cow will always be at the starting position which means
		// we have to check for c-1 cows.
		// If one cow is remaining it means all cow have been placed.
		if (c == 1) {
			return true;
		}
		// If the seperation between the previous cow and the current stall
		// is equal or or greater than the mid value then prev will become the
		// curent position where cow will be placed and decrement cow with 1
		// because 1 cow have already been placed.
		if (pos[i] - prev >= mid) {
			prev = pos[i];
			c--;
		}
	}

	return false;
}

void binary_search(long long* pos, int n, int c) {
	long long left = 0;
	long long right = pos[n - 1] - pos[0];
	long long mid = 0, sep = 0;

	while (left <= right) {
		// Find the mid.
		mid = (left + right) / 2;

		// If this space seperation is valid then update
		// the sep and set the start greater than mid to
		// search for higher possible seperation.
		if (seperation_Possible(pos, mid, n, c)) {
			sep = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	// Print the perfect seperation.
	std::cout << sep << std::endl;
}


void Agressive_cows(long long* pos, int n, int c) {
	// Sort the given position array
	std::sort(pos, pos + n);

	// Check for best seperation between cows
	// using binary search.
	binary_search(pos, n, c);
}

int main() {
	int n = 0, c = 0;
	std::cin >> n >> c;

	long long* pos{ new long long[n] {0} };
	for (int i = 0; i < n; ++i) {
		std::cin >> pos[i];
	}

	Agressive_cows(pos, n, c);

	delete[] pos;
	return 0;
}