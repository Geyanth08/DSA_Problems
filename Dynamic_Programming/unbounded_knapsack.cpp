// Practice link - https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029
// You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - Expontential, Space Complexity - O(W)
int f(int ind, int w, vector<int> &profit, vector<int> &weight)
{
    if (ind == 0)
        return (w / weight[0]) * profit[0];

    int take = -1e9;
    if (w >= weight[ind])
        take = profit[ind] + f(ind, w - weight[ind], profit, weight);
    int notTake = f(ind - 1, w, profit, weight);

    return max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return f(n - 1, w, profit, weight);
}

// Using Memorization -> Time Complexity - O(W*P), Space Complexity - O(W*P) + O(W)
int f(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (ind == 0)
        return (w / weight[0]) * profit[0];
    if (dp[ind][w] != -1)
        return dp[ind][w];

    int take = -1e9;
    if (w >= weight[ind])
        take = profit[ind] + f(ind, w - weight[ind], profit, weight, dp);
    int notTake = f(ind - 1, w, profit, weight, dp);

    return dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, profit, weight, dp);
}

// Using Tabulation -> Time Complexity - O(W*P), Space Complexity - O(W*P)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = weight[0]; i <= w; i++)
        dp[0][i] = (i / weight[0]) * profit[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int v = 0; v <= w; v++)
        {
            int take = -1e9;
            if (v >= weight[ind])
                take = profit[ind] + dp[ind][v - weight[ind]];
            int notTake = dp[ind - 1][v];

            dp[ind][v] = max(take, notTake);
        }
    }

    return dp[n - 1][w];
}

// After Space Otimization -> Time Complexity - O(N*W), Space Complexity - O(W)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0);
    for (int i = weight[0]; i <= w; i++)
        prev[i] = (i / weight[0]) * profit[0];

    for (int ind = 1; ind < n; ind++)
    {
        vector<int> temp(w + 1, 0);
        for (int v = 0; v <= w; v++)
        {
            int take = -1e9;
            if (v >= weight[ind])
                take = profit[ind] + temp[v - weight[ind]];
            int notTake = prev[v];

            temp[v] = max(take, notTake);
        }
        prev = temp;
    }

    return prev[w];
}
