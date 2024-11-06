#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

// Check if placing a queen at board[r][c] is safe
bool isSafe(int r, int c, vector<vector<int>> &board, int n)
{
    // Check upper left diagonal
    int i = r, j = c;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    // Check lower left diagonal
    i = r, j = c;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i++;
        j--;
    }

    // Check left side
    i = r, j = c;
    while (j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        j--;
    }

    return true;
}

// Recursive backtracking function to solve the N-Queens problem
void solve(int col, int firstQueenCol, vector<vector<int>> &board, int n)
{
    // If all queens are placed, print the solution
    if (col == n)
    {
        cnt++;
        for (auto &row : board)
        {
            for (auto &cell : row)
            {
                cout << cell;
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Skip the column where the first queen is already placed
    if (col == firstQueenCol)
    {
        solve(col + 1, firstQueenCol, board, n);
        return;
    }

    // Try placing a queen in all rows for the current column
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, board, n))
        {
            board[i][col] = 1;                       // Place queen
            solve(col + 1, firstQueenCol, board, n); // Recur for next column
            board[i][col] = 0;                       // Backtrack
        }
    }
}

int main()
{
    cout << "Enter the size of matrix: ";
    int n;
    cin >> n;

    // N-Queens is only valid for n >= 4
    if (n < 4)
    {
        cout << "No possible solution for n less than 4" << endl;
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize an empty board

    cout << "Enter the first queen's row and column: " << endl;
    cout << "Enter row: ";
    int r;
    cin >> r;
    cout << "Enter column: ";
    int c;
    cin >> c;

    // Place the first queen
    board[r][c] = 1;

    // Start solving from column 0, skipping the column where the first queen is placed
    solve(0, c, board, n);

    // If no solution is found
    if (cnt == 0)
    {
        cout << "No possible solution for the given input" << endl;
    }

    return 0;
}
