#include <iostream>
#include <vector>

// input function for maze input : 2d vector datatype char
void take_char_inp(std::vector<std::vector<char>>& maze, int row, int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			std::cin >> maze[i][j];
		}
	}
}

// output function for printing solution matrix : 2d vector datatype int
void print_sol(std::vector<std::vector<int>>& arr) {
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[i].size(); ++j) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

bool ratINmaze(std::vector<std::vector<char>>& maze, int row, int col,
	int i, int j, std::vector<std::vector<int>>& sol) {

	// base case
	if (i == row - 1 && j == col - 1) {
		sol[i][j] = 1;
		print_sol(sol);
		return true;
	}

	// recursive case
	sol[i][j] = 1;

	// checking forward path
	if (j <= col - 2 && maze[i][j + 1] != 'X') {
		bool canMoveforward = ratINmaze(maze, row, col, i, j + 1, sol);
		if (canMoveforward) {
			return true;
		}
	}

	// checking downward path
	if (i <= row - 2 && maze[i + 1][j] != 'X') {
		bool canMovedownward = ratINmaze(maze, row, col, i + 1, j, sol);
		if (canMovedownward) {
			return true;
		}
	}

	// backtracking if solution not found
	sol[i][j] = 0;
	// return false
	return false;
}

int main() {
	int row = 0, col = 0;
	std::cin >> row >> col;

	// 2d vector maze for maze input : 2d vector datatype char
	std::vector<char> colm(col);
	std::vector<std::vector<char>> maze(row, colm);

	take_char_inp(maze, row, col);

	// 2d solution vector : 2d vector datatype int
	std::vector<int> colm2(col);
	std::vector<std::vector<int>> sol(row, colm2);

	if (!ratINmaze(maze, row, col, 0, 0, sol))
		std::cout << -1 << std::endl;

	return 0;
}
