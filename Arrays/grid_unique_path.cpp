// Leetcode link - https://leetcode.com/problems/unique-paths/
// Move robot from top-left to bottom-right of the matrix

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - exponential, Space Complexity - Exponential
class Solution
{
public:
    int countPaths(int i, int j, int n, int m)
    {
        if (i == (n - 1) and j == (m - 1))
            return 1;
        if (i >= n or j >= m)
            return 0;
        return countPaths(i, j + 1, n, m) + countPaths(i + 1, j, n, m);
    }

    int uniquePaths(int m, int n)
    {
        int total_paths = countPaths(0, 0, n, m);

        return total_paths;
    }
};

// Using Recursion -> Time Complexity - O(m*n), Space Complexity - O(m*n)
class Solution
{
public:
    int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == (n - 1) and j == (m - 1))
            return 1;
        if (i >= n or j >= m)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = countPaths(i, j + 1, n, m, dp) + countPaths(i + 1, j, n, m, dp);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int total_paths = countPaths(0, 0, n, m, dp);

        return total_paths;
    }
};

// Using Simple Combinations -> Time Complexity - O(m-1) or O(n-1), Space Complexity - O(1)
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int N = m + n - 2;
        int r = m - 1; // we can take n-1 also

        double res = 1;

        for (int i = 1; i <= r; i++)
        {
            res = res * (N - r + i) / i;
        }

        return (int)res;
    }
};