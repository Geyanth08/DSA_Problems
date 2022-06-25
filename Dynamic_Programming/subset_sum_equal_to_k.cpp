// Practice link - https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954
// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

#include <bits/stdc++.h>
using namespace std;

// f(ind,target) : check whether a subsequence exists in array from 0 to ind whose sum is equal to target.
// Using Recursion -> Time Compmlexity - O(2^N), Space Complexity - O(N)
bool f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (target < 0)
        return false;
    if (ind == 0)
    {
        if (arr[0] == target)
            return true;
        return false;
    }

    int pick = f(ind - 1, target - arr[ind], arr);
    int notPick = f(ind - 1, target, arr);

    return (pick or notPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return f(n - 1, k, arr);
}

// Using Memorization -> Time Complexity - O(N*K), Space Complexity - O(N*K) + O(N)
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (target < 0)
        return false;
    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int pick = f(ind - 1, target - arr[ind], arr, dp);
    int notPick = f(ind - 1, target, arr, dp);

    return dp[ind][target] = (pick or notPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, arr, dp);
}

// Using Tabulation -> Time Complexity - O(N*K), Space Complexity - O(N*K)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

// After Space optimization - Time Complexity - O(N*K), Space Complexity - O(K)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);

    prev[0] = true;

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> temp(k + 1, false);
        temp[0] = true;
        for (int target = 1; target <= k; target++)
        {

            bool notTaken = prev[target];

            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];

            temp[target] = notTaken || taken;
        }
        prev = temp;
    }

    return prev[k];
}