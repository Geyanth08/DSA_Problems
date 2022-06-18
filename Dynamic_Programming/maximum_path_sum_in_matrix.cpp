// Practice link - https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998
// Find maximum cost of unique path in a matrix (N X M) to move from first row to last row

#include <bits/stdc++.h>
using namespace std;

// Using Recurison -> Time Complexity - O(3^(N*M)), Space Complexity - O(N)
int f(int i, int j, int col, vector<vector<int>> &matrix)
{
    if (j < 0 or j >= col)
        return -1e9;
    if (i == 0)
        return matrix[0][j];

    int up = matrix[i][j] + f(i - 1, j - 1, col, matrix);
    int leftDiagonal = matrix[i][j] + f(i - 1, j, col, matrix);
    int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, col, matrix);

    return max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int maxi = -1e9;
    for (int i = 0; i < m; i++)
    {
        int colmaxi = f(n - 1, i, m, matrix);
        maxi = max(maxi, colmaxi);
    }

    return maxi;
}

// Using Memorization -> Time Complexity - O(N*M), Space Complexity - O(N) + O(N*M)
int f(int i, int j, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 or j >= col)
        return -1e9;
    if (i == 0)
        return matrix[0][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + f(i - 1, j - 1, col, matrix, dp);
    int leftDiagonal = matrix[i][j] + f(i - 1, j, col, matrix, dp);
    int rightDiagonal = matrix[i][j] + f(i - 1, j + 1, col, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = -1e9;
    for (int i = 0; i < m; i++)
    {
        int colmaxi = f(n - 1, i, m, matrix, dp);
        maxi = max(maxi, colmaxi);
    }

    return maxi;
}

// Using Tabulation -> Time Complexity - O(N*M), Space Complexity - O(N*M)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += dp[i - 1][j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += dp[i - 1][j + 1];
            else
                rightDiagonal += -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = -1e9;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, dp[n - 1][j]);

    return maxi;
}

// After Space Optimization -> Time Complexity - O(N*M), Space Complexity - O(M)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);

    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += prev[j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += prev[j + 1];
            else
                rightDiagonal += -1e9;

            temp[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = temp;
    }

    int maxi = -1e9;
    for (int j = 0; j < m; j++)
        maxi = max(maxi, prev[j]);

    return maxi;
}