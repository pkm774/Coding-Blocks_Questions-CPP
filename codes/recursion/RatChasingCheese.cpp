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

	// else if (maze[i][j] != 'X')
	sol[i][j] = 1;

	// checking forward path (right move)
	if (j <= col - 2 && maze[i][j + 1] != 'X' && sol[i][j + 1] != 1) {
		bool canMoveforward = ratINmaze(maze, row, col, i, j + 1, sol);
		if (canMoveforward) {
			return true;
		}
	}

	// checking backward path (left move)
	if (j >= 1 && maze[i][j - 1] != 'X' && sol[i][j - 1] != 1) {
		bool canMovebackward = ratINmaze(maze, row, col, i, j - 1, sol);
		if (canMovebackward) {
			return true;
		}
	}

	// checking downward path
	if (i <= row - 2 && maze[i + 1][j] != 'X' && sol[i + 1][j] != 1) {
		bool canMovedownward = ratINmaze(maze, row, col, i + 1, j, sol);
		if (canMovedownward) {
			return true;
		}
	}

	// checking upward path
	if (i >= 1 && maze[i - 1][j] != 'X' && sol[i - 1][j] != 1) {
		bool canMoveupward = ratINmaze(maze, row, col, i - 1, j, sol);
		if (canMoveupward) {
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
		std::cout << "NO PATH FOUND" << std::endl;

	return 0;
}

// TEST CASE
// 7 8
// OOOXOOOX
// OXXXOXOX
// OOOOOXOX
// XXXXXXOX
// XOOOOOOX
// XOXXXXXX
// XOOOOOOO
