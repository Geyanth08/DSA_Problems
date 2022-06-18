// Practice link - https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241
// Find total unique paths in a matrix (M X N) to move from top-left (0,0) to bottom-right (M-1,N-1).
// Obstacles are present in the matrix, denoted by -1.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^(M X N)), Space Complexity - O((M-1) + (N-1))
int totalPaths(int i, int j, vector<vector<int>> &mat)
{
    if (i >= 0 and j >= 0 and mat[i][j] == -1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    int up = 0, left = 0;
    up = totalPaths(i - 1, j, mat);
    left = totalPaths(i, j - 1, mat);

    return up + left;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    return totalPaths(n - 1, m - 1, mat);
}

// Using Memorization -> Time Complexity - O(M X N), Space Complexity - O((M-1) + (N-1)) + O(M X N)
int mod = (int)(10e9 + 7);
int totalPaths(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i >= 0 and j >= 0 and mat[i][j] == -1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = 0, left = 0;
    up = totalPaths(i - 1, j, mat, dp);
    left = totalPaths(i, j - 1, mat, dp);

    return dp[i][j] = (up + left) % mod;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return totalPaths(n - 1, m - 1, mat, dp);
}

// Using Tabulation -> Time Complexity - O(M X N), Space Complexity - O(M X N)
int mod = (int)(10e9 + 7);
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i >= 0 and j >= 0 and mat[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 and j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return (dp[n - 1][m - 1]) % mod;
}

// After Space Optimization -> Time Complexity - O(N X M), Space Complexity - O(M)
int mod = (int)(10e9 + 7);
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i >= 0 and j >= 0 and mat[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }
            if (i == 0 and j == 0)
            {
                temp[j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];

            temp[j] = up + left;
        }
        prev = temp;
    }

    return (prev[m - 1]) % mod;
}
