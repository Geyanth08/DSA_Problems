// Practice link - https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
// Find Minimum cost of unique path in a matrix (M X N) to move from top-left (0,0) to bottom-right (M-1,N-1).

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^(M X N)), Space Complexity - O((M-1) + (N-1))
int f(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 and j == 0)
        return grid[0][0];
    if (i < 0 or j < 0)
        return 1e5;

    int up, left;
    up = grid[i][j] + f(i - 1, j, grid);
    left = grid[i][j] + f(i, j - 1, grid);

    return min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    int minSum = f(grid.size() - 1, grid[0].size() - 1, grid);
}

// Using Memorization -> Time Complexity - O(M X N), Space Complexity - O((M-1) + (N-1)) + O(M X N)
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return grid[0][0];
    if (i < 0 or j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up, left;
    up = grid[i][j] + f(i - 1, j, grid, dp);
    left = grid[i][j] + f(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, grid, dp);
}

// Using Tabulation -> Time Complexity - O(M X N), Space Complexity - O(M X N)
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = grid[0][0];
                continue;
            }

            int up = grid[i][j];
            if (i > 0)
                up += dp[i - 1][j];
            else
                up += 1e9;

            int left = grid[i][j];
            if (j > 0)
                left += dp[i][j - 1];
            else
                left += 1e9;

            dp[i][j] = min(up, left);
        }
    }
    return dp[n - 1][m - 1];
}

// After Space Optimization -> Time Complexity - O(M X N), Space Complexity - O(N)
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
            {
                temp[j] = grid[0][0];
                continue;
            }

            int up = grid[i][j];
            if (i > 0)
                up += prev[j];
            else
                up += 1e9;

            int left = grid[i][j];
            if (j > 0)
                left += temp[j - 1];
            else
                left += 1e9;

            temp[j] = min(up, left);
        }
        prev = temp;
    }
    return prev[m - 1];
}