#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Board Size 20x20 filled with 0
int board[20][20] = { 0 };
// For calculating total possibilities
int total_possiblities = 0;

// Function to print the bord
void printBoard(int board[20][20], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) {
                cout << 'Q' << ' ';
            }
            else {
                cout << '_' << ' ';
            }
        }
        cout << endl;
    }
}

bool canBePlaced(int board[20][20], int i, int j, int  n) {

    // vertical check
    for (int v = 0; v < i; ++v) {
        if (board[v][j] == 1) {
            return false;
        }
    }

    // Copy variables for right upper diagonal check
    int u = i, v = j;

    // upper left diagonal check
    while (i >= 0 && j >= 0) {
        if(board[i][j] == 1) {
            return false;
        }
        --i;
        --j;
    }

    // upper right diagonal
    while (u >= 0 && v < n) {
        if (board[u][v] == 1) {
            return false;
        }
        --u;
        ++v;
    }

    return true;
}

// Main recursive function
bool NQueen(int board[20][20], int n, int i) {
    // base case
    if (i == n) {
        ++total_possiblities;
        printBoard(board, n);
        // Endl for printing next possible board
        cout << endl;
        // Return true for printing first possibility
        //return true;
        // Return false for printing all possibility
        return false;
    }

    // recursive case
    for (int j = 0; j < n; ++j) {
        if (canBePlaced(board, i, j, n)) {
            board[i][j] = 1;
            bool remaining_result = NQueen(board, n, i + 1);
            if (remaining_result) {
                return true;
            }
            else {
                board[i][j] = 0;
            }
        }
    }

    return false;
}

int main() {

    int n = 0;
    cin >> n;

    // Works only for board greater than or equal to 4
    if (n <= 3) {
        return 0;
    }

    NQueen(board, n, 0);
    cout << endl << "Total Possibilities = " << total_possiblities << endl;

    return 0;
}
