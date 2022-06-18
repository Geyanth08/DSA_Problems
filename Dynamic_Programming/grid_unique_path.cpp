// Practice link - https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
// Find total unique paths in a matrix (M X N) to move from top-left (0,0) to bottom-right (M-1,N-1).

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^(M X N)), Space Complexity - O((M-1) + (N-1))
int totalPaths(int i, int j)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    int up = totalPaths(i - 1, j);
    int left = totalPaths(i, j - 1);

    return up + left;
}
int uniquePaths(int m, int n)
{
    return totalPaths(m - 1, n - 1);
}

// Using Memorization -> Time Complexity - O(M X N), Space Complexity - O((M-1) + (N-1)) + O(M X N)
int totalPaths(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = totalPaths(i - 1, j, dp);
    int left = totalPaths(i, j - 1, dp);

    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return totalPaths(m - 1, n - 1, dp);
}

// Using Tabulation -> Time Complexity - O(M X N), Space Complexity - O(M X N)
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int left = 0, up = 0;
            if (j > 0)
                left = dp[i][j - 1];
            if (i > 0)
                up = dp[i - 1][j];

            dp[i][j] = left + up;
        }
    }

    return dp[m - 1][n - 1];
}

// After Space Optimization -> Time Complexity - O(M X N), Space Complexity - O(N)
int uniquePaths(int m, int n)
{
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++)
    {

        vector<int> cur(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
            {
                cur[j] = 1;
                continue;
            }

            int left = 0, up = 0;
            if (j > 0)
                left = cur[j - 1];
            if (i > 0)
                up = prev[j];

            cur[j] = left + up;
        }

        prev = cur;
    }

    return prev[n - 1];
}