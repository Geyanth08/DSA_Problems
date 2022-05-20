// Leetcode link - https://leetcode.com/problems/n-queens/
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

// Placing Queens Column-wise -> Time Complexity - O(N^3), Space Complexity - O(N^2)
class Solution
{
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {

        // Upper Diagonal
        int tempRow = row;
        int tempCol = col;
        while (row >= 0 and col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // Horizontal <-- Q
        row = tempRow;
        col = tempCol;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Lower diagonal
        row = tempRow;
        col = tempCol;
        while (row < n and col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
            row++;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};