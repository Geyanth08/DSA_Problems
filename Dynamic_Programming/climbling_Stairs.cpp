// Practice link - https://leetcode.com/problems/climbing-stairs/
// You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps.
//  Return the number of distinct ways in which you can climb from the 0th step to Nth step.

#include <bits/stdc++.h>
using namespace std;

// Using Recursion -> Time Complexity - O(2^N), Space Complexity - O(1) + O(N) auxillary stack space
class Solution1
{
public:
    int f(int n)
    {
        // Base Conditions
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        // we can either move one step or two step
        return f(n - 1) + f(n - 2);
    }

    int climbStairs(int n)
    {

        return f(n);
    }
};

// Using Memorization -> Time Complexity - O(N), Space Complexity - O(N) + O(N) auxillary stack space
class Solution2
{
public:
    int f(int n, vector<int> &dp)
    {
        // Base Conditions
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        // Overlapping Subproblem then fetch from dp array
        if (dp[n] != -1)
            return dp[n];

        // we can either move one step or two step
        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

// Using Tabulation -> Time Complexity - O(N), Space Complexity - O(N)
class Solution3
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);

        // Initialisation
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// After Space Optimization -> Time Complexity - O(N), Space Complexity - O(1)
class Solution
{
public:
    int climbStairs(int n)
    {

        // Initialisation
        int prev2 = 1;
        int prev = 1;
        int curr;

        for (int i = 2; i <= n; i++)
        {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};