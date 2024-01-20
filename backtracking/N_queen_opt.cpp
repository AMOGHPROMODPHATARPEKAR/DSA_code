#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//optimised
void addSol(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n,
            unordered_map<int, bool> &rowSet,
            unordered_map<int, bool> &upperDiagonalSet,
            unordered_map<int, bool> &lowerDiagonalSet)
{

    // Check for the current column in the current row
    if (rowSet[row])
    {
        return false;
    }

    // Check for upper diagonal
    int upperDiagonal = n - 1 + col - row ;
    if (upperDiagonalSet[upperDiagonal])
    {
        return false;
    }

    // Check for lower diagonal
    int lowerDiagonal = row + col;
    if (lowerDiagonalSet[lowerDiagonal])
    {
        return false;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n,
           unordered_map<int, bool> &rowSet,
           unordered_map<int, bool> &upperDiagonalSet,
           unordered_map<int, bool> &lowerDiagonalSet)
{
    if (col == n)
    {
        addSol(ans, board, n);
        return;
    }

    // solve one case, rest will be handled by recursion

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n, rowSet, upperDiagonalSet, lowerDiagonalSet))
        {
            // safe
            board[row][col] = 1;
            rowSet[row] = true;
            upperDiagonalSet[n - 1 + col - row] = true;
            lowerDiagonalSet[row + col] = true;

            solve(col + 1, ans, board, n, rowSet, upperDiagonalSet, lowerDiagonalSet);

            // backtrack
            board[row][col] = 0;
            rowSet[row] = false;
            upperDiagonalSet[n - 1 + col - row] = false;
            lowerDiagonalSet[row + col] = false;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    unordered_map<int, bool> rowSet;
    unordered_map<int, bool> upperDiagonalSet;
    unordered_map<int, bool> lowerDiagonalSet;

    solve(0, ans, board, n, rowSet, upperDiagonalSet, lowerDiagonalSet);
    return ans;
}

int main()
{
    // Example usage
    int n = 4;
    vector<vector<int>> result = solveNQueens(n);

    // Displaying the result
    for (const auto &solution : result)
    {
        for (int val : solution)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
