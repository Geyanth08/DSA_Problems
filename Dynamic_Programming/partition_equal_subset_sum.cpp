// Practice link - https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980
// You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.

#include <bits/stdc++.h>
using namespace std;

// Using Reccursion -> Time Complexity - O(2^N), Space Complexity - O(N)
bool f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;
    if (target < 0)
        return false;

    int take = f(ind - 1, target - arr[ind], arr);
    int notTake = f(ind - 1, target, arr);

    return take or notTake;
}
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total += arr[i];
    }
    if (total % 2)
        return false;
    return f(arr.size() - 1, total / 2, arr);
}

// Using Memorisation -> Time Complexity - O(N*K) + O(N), Space Complexity - O(N*K) + O(N)
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return arr[0] == target;
    if (target < 0)
        return false;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int take = f(ind - 1, target - arr[ind], arr, dp);
    int notTake = f(ind - 1, target, arr, dp);

    return dp[ind][target] = take or notTake;
}
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total += arr[i];
    }
    if (total % 2)
        return false;

    vector<vector<int>> dp(n, vector<int>((total / 2) + 1, -1));

    return f(arr.size() - 1, total / 2, arr, dp);
}

// Using Tabulation -> Time Complexity - O(N*K) + O(N), Space Complexity - O(N*K)
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total += arr[i];
    }
    if (total % 2)
        return false;

    vector<vector<bool>> dp(n, vector<bool>((total / 2) + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= total / 2)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int tar = 1; tar <= total / 2; tar++)
        {
            bool take = false;
            if (arr[i] <= tar)
                take = dp[i - 1][tar - arr[i]];

            bool notTake = dp[i - 1][tar];

            dp[i][tar] = take or notTake;
        }
    }
    return dp[n - 1][total / 2];
}

// After Space Optimization -> Time Complexity - O(N*K) + O(N), Space Complexity - O(total/2)
bool canPartition(vector<int> &arr, int n)
{
    int total = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        total += arr[i];
    }
    if (total % 2)
        return false;

    vector<bool> prev((total / 2) + 1, false);

    prev[0] = true;
    if (arr[0] <= total / 2)
        prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        vector<bool> temp((total / 2) + 1, false);
        temp[0] = true;
        for (int tar = 1; tar <= total / 2; tar++)
        {
            bool take = false;
            if (arr[i] <= tar)
                take = prev[tar - arr[i]];

            bool notTake = prev[tar];

            temp[tar] = take or notTake;
        }
        prev = temp;
    }
    return prev[total / 2];
}
