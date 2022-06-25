// Practice link - https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284
// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - Exponentital, Space Complexity - O(N)
int f(int ind, int target, vector<int> &price)
{
    if (ind == 0)
        return target * price[0];

    int take = -1e9;
    int rodLength = ind + 1;
    if (target >= rodLength)
        take = price[ind] + f(ind, target - rodLength, price);
    int notTake = f(ind - 1, target, price);

    return max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    return f(n - 1, n, price);
}

// Using Memorization -> Time Complexity - O(N*N), Space Complexity - O(N*N) + O(N)
int f(int ind, int target, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return target * price[0];
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int take = -1e9;
    int rodLength = ind + 1;
    if (target >= rodLength)
        take = price[ind] + f(ind, target - rodLength, price, dp);
    int notTake = f(ind - 1, target, price, dp);

    return dp[ind][target] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

// Using Tabulation -> Time Complexity - O(N*N), Space Complexity - O(N*N)
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[0][i] = i * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int len = 0; len <= n; len++)
        {
            int take = -1e9;
            int rodLength = i + 1;
            if (len >= rodLength)
                take = price[i] + dp[i][len - rodLength];
            int notTake = dp[i - 1][len];

            dp[i][len] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

// After Space Optimization -> Time Complexity - O(N*N), Space Complexity - O(N)
int cutRod(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);

    for (int i = 0; i <= n; i++)
        prev[i] = i * price[0];

    for (int i = 1; i < n; i++)
    {
        for (int len = 0; len <= n; len++)
        {
            int take = -1e9;
            int rodLength = i + 1;
            if (len >= rodLength)
                take = price[i] + prev[len - rodLength];
            int notTake = prev[len];

            prev[len] = max(take, notTake);
        }
    }

    return prev[n];
}
