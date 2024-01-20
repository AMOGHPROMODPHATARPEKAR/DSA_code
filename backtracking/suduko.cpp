#include <bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, int val, vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        // Check for row
        if (board[row][i] == val) {
            return false;
        }

        // Check for col
        if (board[i][col] == val) {
            return false;
        }

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, val, board)) {
                        board[row][col] = val;
                        // Recursive
                        bool ans = solve(board);
                        if (ans) {
                            return true;
                        } else {
                            // Backtracking
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}

int main() {
    // Example usage
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    solveSudoku(sudoku);

    // Displaying the solved Sudoku
    for (const auto& row : sudoku) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
