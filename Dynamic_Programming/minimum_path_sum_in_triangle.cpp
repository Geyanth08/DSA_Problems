// Practice link - https://www.codingninjas.com/codestudio/problems/triangle_1229398
// Find Minimum cost of unique path in a triangle of N rows to move from top (0,0) to bottom (N-1,..).

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^(N*N)), Space Complexity - O(N)
int f(int i, int j, vector<vector<int>> &triangle, int n)
{
    if (i == n)
        return triangle[i][j];

    int down = triangle[i][j] + f(i + 1, j, triangle, n);
    int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, n);

    return min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    return f(0, 0, triangle, n - 1);
}

// Using Memorization -> Time Complexity - O(N*N), Space Complexity - O(N) + O(N*N)
int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    if (i == n)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + f(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, n - 1, dp);
}

// Using Tabulation -> Time Complexity - O(N*N), Space Complexity - O(N*N)
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// After Space Optimization -> Time Complexity - O(N*N), Space Complexity - O(N)
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < n; i++)
    {
        prev[i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n, 0);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + prev[j];
            int diagonal = triangle[i][j] + prev[j + 1];

            temp[j] = min(down, diagonal);
        }
        prev = temp;
    }
    return prev[0];
}