// Practice link - https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542
// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi.
// Return the maximum value that a thief can generate by stealing items.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^(N*W)), Space Complexity - O(N)
int f(int ind, int W, vector<int> &weight, vector<int> &value)
{
    if (ind == 0)
    {
        if (weight[0] <= W)
            return value[0];
        return 0;
    }

    int take = -1e9;
    if (weight[ind] <= W)
        take = value[ind] + f(ind - 1, W - weight[ind], weight, value);

    int notTake = 0 + f(ind - 1, W, weight, value);

    return max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return f(n - 1, maxWeight, weight, value);
}

// Using Memorization -> Time Complexity - O(N*W), Space Complexity - O(N*W) + O(N)
int f(int ind, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[0] <= W)
            return value[0];
        return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];

    int take = -1e9;
    if (weight[ind] <= W)
        take = value[ind] + f(ind - 1, W - weight[ind], weight, value, dp);

    int notTake = 0 + f(ind - 1, W, weight, value, dp);

    return dp[ind][W] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(n - 1, maxWeight, weight, value, dp);
}

// Using Tabulation -> Time Complexity - O(N*W), Space Complexity - O(N*W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int cap = 0; cap <= maxWeight; cap++)
        {
            int take = -1e9;
            if (weight[i] <= cap)
                take = value[i] + dp[i - 1][cap - weight[i]];

            int notTake = 0 + dp[i - 1][cap];

            dp[i][cap] = max(take, notTake);
        }
    }

    return dp[n - 1][maxWeight];
}

// After Space Optimization -> Time Complexity - O(N*W), Space Complexity - O(W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int i = weight[0]; i <= maxWeight; i++)
        prev[i] = value[0];

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(maxWeight + 1, 0);
        for (int cap = maxWeight; cap >= 0; cap--)
        {
            int take = -1e9;
            if (weight[i] <= cap)
                take = value[i] + prev[cap - weight[i]];

            int notTake = 0 + prev[cap];

            prev[cap] = max(take, notTake);
        }
    }

    return prev[maxWeight];
}