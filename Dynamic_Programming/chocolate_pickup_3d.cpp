// Practice link - https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885
// Find maximum total chocolates collected by alice and bob in a grid (N X M) startinf from (0,0) and (0,M-1) to last row (N-1).

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(9^(N*M*M)), Space Complexity - O(N)
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
    if (j1 < 0 or j1 >= c or j2 < 0 or j2 >= c)
        return -1e9;

    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    int maxi = -1e9;

    for (int n1 = -1; n1 <= 1; n1++)
    {
        for (int n2 = -1; n2 <= 1; n2++)
        {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + f(i + 1, j1 + n1, j2 + n2, r, c, grid);
            else
                ans = grid[i][j1] + grid[i][j2] + f(i + 1, j1 + n1, j2 + n2, r, c, grid);

            maxi = max(maxi, ans);
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    return f(0, 0, c - 1, r, c, grid);
}

// Using Memorization -> Time Complexity - O(9*(N*M*M)), Space Complexity - O(M) + O(N*M*M)
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 or j1 >= c or j2 < 0 or j2 >= c)
        return -1e9;

    if (i == r - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e9;

    for (int n1 = -1; n1 <= 1; n1++)
    {
        for (int n2 = -1; n2 <= 1; n2++)
        {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + f(i + 1, j1 + n1, j2 + n2, r, c, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + f(i + 1, j1 + n1, j2 + n2, r, c, grid, dp);

            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c - 1, r, c, grid, dp);
}