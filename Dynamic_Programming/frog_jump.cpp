// Practice link - https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
// Given heights of stairs and frog can jump only one step or two step
// find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^N), Space Complexity - O(N) for auxillary stack space
int f(int ind, vector<int> &heights)
{
    if (ind == 0)
        return 0;
    if (ind < 0)
        return 1e3;

    int jumpOne = abs(heights[ind] - heights[ind - 1]) + f(ind - 1, heights);
    int jumpTwo = abs(heights[ind] - heights[ind - 2]) + f(ind - 2, heights);

    return min(jumpOne, jumpTwo);
}

int frogJump(int n, vector<int> &heights)
{
    return f(n - 1, heights);
}

// Using Memorization -> Time Complexity - O(N), Space Complexity - O(N) + O(N) for auxillary stack space
int f(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (ind < 0)
        return 1e3;
    if (dp[ind] != -1)
        return dp[ind];

    int oneStep = abs(height[ind] - height[ind - 1]) + f(ind - 1, height, dp);
    int twoStep = abs(height[ind] - height[ind - 2]) + f(ind - 2, height, dp);

    return dp[ind] = min(oneStep, twoStep);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return f(n - 1, heights, dp);
}

// Using Tabulation -> Time Complexity - O(N), Space Complexity - O(N)
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    int jumpOne = 0, jumpTwo = 1e3;

    for (int i = 1; i < n; i++)
    {
        jumpOne = abs(heights[i] - heights[i - 1]) + dp[i - 1];
        if (i > 1)
            jumpTwo = abs(heights[i] - heights[i - 2]) + dp[i - 2];

        dp[i] = min(jumpOne, jumpTwo);
    }

    return dp[n - 1];
}

// After Space Optimization -> Time Complexity - O(N), Space Complexity - O(1)
int frogJump(int n, vector<int> &height)
{
    int prev = 0, prev2 = 0, curr;
    int jumpOne = 0, jumpTwo = 1e3;

    for (int i = 1; i < n; i++)
    {
        jumpOne = abs(height[i] - height[i - 1]) + prev;
        if (i > 1)
            jumpTwo = abs(height[i] - height[i - 2]) + prev2;

        curr = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = curr;
    }

    return curr;
}