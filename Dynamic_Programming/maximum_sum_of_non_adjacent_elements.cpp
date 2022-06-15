// Practice link - https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
// You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^N), Space Complexity - O(N) auxiliary stack space
int f(int ind, vector<int> &nums)
{
    if (ind == 0)
        return nums[0];
    if (ind < 0)
        return 0;

    int pick = nums[ind] + f(ind - 2, nums);
    int notPick = f(ind - 1, nums);

    return max(pick, notPick);
}

int maximumNonAdjacentSum1(vector<int> &nums)
{
    int n = nums.size();
    return f(n - 1, nums);
}

// Using Memorization -> Time Complexity - O(N), Space Complexity - O(N) + O(N) auxiliary stack space
int f(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[0];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int notPick = f(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}

int maximumNonAdjacentSum2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    return f(n - 1, nums, dp);
}

// Using Tabulation -> Time Complexity - O(N), Space Complexity - O(N)
int maximumNonAdjacentSum3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}

// After Space Optimization -> Time Complexity - O(N), Space Complexity - O(1)
int maximumNonAdjacentSum4(vector<int> &nums)
{
    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;
    int curr;

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
            pick += prev2;
        int notPick = prev;

        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}