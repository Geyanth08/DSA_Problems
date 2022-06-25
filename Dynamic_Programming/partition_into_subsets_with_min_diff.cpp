// Practice link - https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.

#include <bits/stdc++.h>
using namespace std;

// Last row of DP array in subset sum problem specify that whether a particular sum (0 to target) is possible with the given array.
// Using Memorization -> Time Complexity - O(N*total) + O(N) + O(N), Space Complexity - O(N*total) + O(N)
bool subsetSum(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;
    if (ind == 0)
        return dp[ind][target] = arr[0] == target;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool take = false;
    if (arr[ind] <= target)
        take = subsetSum(ind - 1, target - arr[ind], arr, dp);

    bool notTake = subsetSum(ind - 1, target, arr, dp);

    return dp[ind][target] = take or notTake;
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(total + 1, -1));
    for (int i = 0; i <= total; i++)
    {
        bool dummy = subsetSum(n - 1, i, arr, dp);
    }

    int mini = 1e9;
    for (int i = 0; i <= total; i++)
    {
        if (dp[n - 1][i])
        {
            int diff = abs(i - (total - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// Using Tabulation -> Time Complexity - O(N*total) + O(N) + O(N), Space Complexity - O(N*total)
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(total + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= total)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 1; tar <= total; tar++)
        {
            bool take = false;
            if (arr[ind] <= tar)
                take = dp[ind - 1][tar - arr[ind]];

            bool notTake = dp[ind - 1][tar];

            dp[ind][tar] = take or notTake;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= total; i++)
    {
        if (dp[n - 1][i])
        {
            int diff = abs(i - (total - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// After Space Otmization - Time Complexity - O(N*total) + O(N) + O(N), Space Complexity - O(total)
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    vector<bool> prev(total + 1, false);
    prev[0] = true;

    if (arr[0] <= total)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> temp(total + 1, false);
        temp[0] = true;
        for (int tar = 1; tar <= total; tar++)
        {
            bool take = false;
            if (arr[ind] <= tar)
                take = prev[tar - arr[ind]];

            bool notTake = prev[tar];

            temp[tar] = take or notTake;
        }
        prev = temp;
    }

    int mini = 1e9;
    for (int i = 0; i <= total; i++)
    {
        if (prev[i])
        {
            int diff = abs(i - (total - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}
