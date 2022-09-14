#include <iostream>
#include <vector>

int sum = 0, count = 0, maximum = 0;

void board_Input(std::vector<std::vector<int>>& board, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cin >> board[i][j];
			if (board[i][j]) {
				++sum;
			}
		}
	}
}

void board_Print(std::vector<std::vector<int>> board, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void check_Path(std::vector<std::vector<int>>& board,
	int size, int i, int j, int count) {

	// base case
	if (i < 0 || i > size - 1 || j < 0 ||  j > size - 1 || board[i][j] == 0) {
		return;
	}

	// recursive case

	// set the visited cell to 0 so that
	// same path will not be counted
	board[i][j] = 0;

	// global maximum is used to store
	// the maximum of value of visited squares.
	// starting position is set as 0 as we
	// have already visited that square
	// therefore +1 increment in count
	maximum = std::max(maximum, count + 1);

	// check through every path and increment in
	// count if any square have been visited
	check_Path(board, size, i - 2, j - 1, count + 1);
	check_Path(board, size, i - 2, j + 1, count + 1);
	check_Path(board, size, i - 1, j - 2, count + 1);
	check_Path(board, size, i - 1, j + 2, count + 1);
	check_Path(board, size, i + 1, j - 2, count + 1);
	check_Path(board, size, i + 1, j + 2, count + 1);
	check_Path(board, size, i + 2, j - 1, count + 1);
	check_Path(board, size, i + 2, j + 1, count + 1);

	// set board[i][j] = 1 again for backtracking
	// if path not found
	board[i][j] = 1;
}

int main() {
	int size = 0;
	std::cin >> size;

	// Create a 2D board Vector
	std::vector<int> col(size);
	std::vector<std::vector<int>> board(size, col);

	// Take the input matrix
	// and count number of 1 present
	board_Input(board, size);

	// Check and count no of paths present
	check_Path(board, size, 0, 0, 0);

	// Print the minimum number of
	// squares that the knight cannot reach
	std::cout << sum - maximum << std::endl;

	return 0;
}
